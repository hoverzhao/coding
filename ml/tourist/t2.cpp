int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    SparseTable st(x, [&](int i, int j) {
      return min(i, j);
    });
    vector<vector<int>> at(n + 1);
    for (int i = 0; i < n; i++) {
      at[x[i]].push_back(i);
    }
    vector<int> v = {0};
    vector<int> u = {0};
    vector<int> pr(n, -1);
    vector<int> ne(n, -1);
    auto Insert = [&](int l, int r, int i) {
      pr[i] = l;
      ne[i] = r;
      if (l != -1) {
        ne[l] = i;
      }
      if (r != -1) {
        pr[r] = i;
      }
    };
    bool fail = false;
    for (int i = 1; i < n; i++) {
      if (x[i] > x[i - 1] + 1) {
        fail = true;
        break;
      }
      if (x[i] == x[i - 1] + 1) {
        int q = 0;
        auto it = lower_bound(at[x[i]].begin(), at[x[i]].end(), i + 1);
        if (it != at[x[i]].end()) {
          int j = *it;
          if (st.get(i, j) >= x[i]) {
            q = 1;
          }
        }
        if (q == 1 && v.back() == 1) {
          fail = true;
          break;
        }
        if (q == 0) {
          Insert(pr[i - 1], i - 1, i);
        } else {
          Insert(i - 1, ne[i - 1], i);
        }
        v.push_back(q);
        u.push_back(i);
        continue;
      }
      if (v[x[i] - 1] == 0) {
        fail = true;
        break;
      }
      v.resize(x[i]);
      u.resize(x[i]);
      Insert(u.back(), ne[u.back()], i);
      u.back() = i;
    }
    if (fail) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      int root = -1;
      for (int i = 0; i < n; i++) {
        if (pr[i] == -1) {
          root = i;
        }
      }
      vector<int> a(n, -1);
      for (int i = 0; i < n; i++) {
        assert(root != -1);
        a[root] = i + 1;
        root = ne[root];
      }
      assert(root == -1);
      for (int i = 0; i < n; i++) {
        assert(a[i] != -1);
        cout << a[i] << " \n"[i == n - 1];
      }
    }
  }
  return 0;
}
