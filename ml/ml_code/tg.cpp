int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937 rng_local(58);
  int tt;
  cin >> tt;
  int MAX_Q = 0;
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    cin >> n;
    #ifdef LOCAL
      vector<int> real_p(n);
      iota(real_p.begin(), real_p.end(), 0);
      if (0) {
        auto cp = real_p;
        shuffle(cp.begin(), cp.end(), rng_local);
        int ptr = 0;
        if (n % 2 == 1) {
          real_p[cp[0]] = cp[1];
          real_p[cp[1]] = cp[2];
          real_p[cp[2]] = cp[0];
          ptr += 3;
        }
        while (ptr < n - 1) {
          real_p[cp[ptr]] = cp[ptr + 1];
          real_p[cp[ptr + 1]] = cp[ptr];
          ptr += 2;
        }
      } else {
        while (true) {
          shuffle(real_p.begin(), real_p.end(), rng_local);
          bool ok = true;
          for (int i = 0; i < n; i++) {
            if (real_p[i] == i) {
              ok = false;
              break;
            }
          }
          if (ok) {
            break;
          }
        }
      }
    #endif
    int k = (n - 1) / 2;
    cout << k + 1 << endl;
    int Q = 0;
    map<vector<int>, int> memo;
    auto Ask = [&](vector<int> q) {
      if (memo.find(q) != memo.end()) {
        return memo[q];
      }
      ++Q;
      cout << "?";
      for (int i = 0; i < n; i++) {
        cout << " " << q[i] + 1;
      }
      cout << endl;
      #ifdef LOCAL
        int got = 0;
        for (int i = 0; i < n; i++) {
          if (i != k) {
            for (int j = i + 1; j < n; j++) {
              if (real_p[q[i]] == q[j]) {
                got += 1;
              }
            }
          }
        }
      #else
        int got;
        cin >> got;
      #endif
      return memo[q] = got;
    };
    mt19937 rng(8471246);
    vector<int> p(n, -1);
    int me = -1;
    int prv = -1;
    for (int iter = 0; iter < n - 2; iter++) {
      if (me == -1) {
        assert(prv == -1);
        for (int i = 0; i < n; i++) {
          if (p[i] == -1) {
            me = i;
            break;
          }
        }
      }
      vector<int> all;
      for (int i = 0; i < n; i++) {
        if (i != me) {
          all.push_back(i);
        }
      }
      auto MakeQ = [&]() {
        vector<int> q(n);
        int ptr = 0;
        for (int i = 0; i < n; i++) {
          if (i == k) {
            q[i] = me;
          } else {
            q[i] = all[ptr++];
          }
        }
        return q;
      };
      vector<int> cans;
      for (int i = 0; i < n; i++) {
        if (i == me) continue;
        bool ok = true;
        for (int j = 0; j < n; j++) {
          if (p[j] == i) ok = false;
        }
        if (ok) cans.push_back(i);
      }
      while (true) {
        if (prv != -1 && n > 20) {
          shuffle(cans.begin(), cans.end(), rng);
          all.assign(n - 1, -1);
          for (int i = 0; i < k && i < int(cans.size()); i++) {
            all[i] = cans[i];
          }
          vector<int> rest;
          for (int i = 0; i < n; i++) {
            if (i == me) continue;
            bool ok = true;
            for (int j = 0; j < n - 1; j++) if (all[j] == i) ok = false;
            if (ok) rest.push_back(i);
          }
          shuffle(rest.begin(), rest.end(), rng);
          int ptr = 0;
          for (int i = 0; i < n - 1; i++) {
            if (all[i] == -1) all[i] = rest[ptr++];
          }
        } else {
          while (true) {
            shuffle(all.begin(), all.end(), rng);
            break;
            int cc = 0;
            for (int i = k; i < 2 * k; i++) {
              if (find(cans.begin(), cans.end(), all[i]) != cans.end()) cc += 1;
            }
            // debug(p, cans, me, prv, cc, all);
            if (prv != -1 && 2 * cc > int(cans.size())) break;
            if (abs(2 * cc - int(cans.size())) <= (prv == -1 ? 2 : 2)) {
              break;
            }
          }
        }
        // debug("hi");
        vector<int> q = MakeQ();
        auto got = Ask(q);
        rotate(all.begin(), all.begin() + k, all.end());
        q = MakeQ();
        auto new_got = Ask(q);
        int add = 0;
        for (int i = 0; i < k; i++) {
          add |= int(q[i] == prv);
        }
        // debug(new_got - add, got - 1);
        if (new_got - add == got - 1) {
          vector<int> vals;
          vals.push_back(0);
          for (int i = 1; i <= k; i++) {
            if (find(cans.begin(), cans.end(), all[n - 1 - i]) != cans.end()) vals.push_back(i);
          }
          int low = 0, high = int(vals.size()) - 1;
          while (low + 1 < high) {
            int mid = (low + high) >> 1;
            int md = vals[mid];
            rotate(all.begin(), all.end() - md, all.end());
            q = MakeQ();
            new_got = Ask(q);
            add = 0;
            for (int i = md; i < k; i++) {
              add |= int(q[i] == prv);
            }
            if (new_got - add == got) {
              high = mid;
            } else {
              low = mid;
            }
            rotate(all.begin(), all.begin() + md, all.end());
          }
          high = vals[high];
          rotate(all.begin(), all.end() - high, all.end());
          p[me] = all[0];
          break;
        }
      }
      if (p[p[me]] == -1) {
        prv = me;
        me = p[me];
      } else {
        prv = me = -1;
      }
    }
    if (prv == -1) {
      vector<int> xs;
      for (int i = 0; i < n; i++) {
        if (p[i] == -1) {
          xs.push_back(i);
        }
      }
      assert(xs.size() == 2);
      p[xs[0]] = xs[1];
      p[xs[1]] = xs[0];
    } else {
      int other = -1;
      for (int i = 0; i < n; i++) {
        if (p[i] == -1 && i != me) {
          other = i;
          break;
        }
      }
      assert(other != -1);
      p[me] = other;
      int sum = accumulate(p.begin(), p.end(), 0) - (-1);
      p[other] = n * (n - 1) / 2 - sum;
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
      cout << " " << p[i] + 1;
    }
    cout << endl;
    MAX_Q = max(MAX_Q, Q);
    #ifdef LOCAL
      debug(tt, qq, n, real_p == p, MAX_Q, Q, 10 * n);
    #endif
    assert(Q <= 10 * n);
  }
  return 0;
  //Codeforces Round 1042 (Div. 3)
}
