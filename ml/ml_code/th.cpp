ypedef long double ld;
 
const ld eps = 1e-8;
 
vector<ld> simplex(vector<vector<ld>> a) {
  int n = (int) a.size() - 1;
  int m = (int) a[0].size() - 1;
  vector<int> left(n + 1);
  vector<int> up(m + 1);
  iota(left.begin(), left.end(), m);
  iota(up.begin(), up.end(), 0);
  auto pivot = [&](int x, int y) {
    swap(left[x], up[y]);
    ld k = a[x][y];
    a[x][y] = 1;
    vector<int> pos;
    for (int j = 0; j <= m; j++) {
      a[x][j] /= k;
      if (fabs(a[x][j]) > eps) {
        pos.push_back(j);
      }
    }
    for (int i = 0; i <= n; i++) {
      if (fabs(a[i][y]) < eps || i == x) {
        continue;
      }
      k = a[i][y];
      a[i][y] = 0;
      for (int j : pos) {
        a[i][j] -= k * a[x][j];
      }
    }
  };
  while (1) {
    int x = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i][0] < -eps && (x == -1 || a[i][0] < a[x][0])) {
        x = i;
      }
    }
    if (x == -1) {
      break;
    }
    int y = -1;
    for (int j = 1; j <= m; j++) {
      if (a[x][j] < -eps && (y == -1 || a[x][j] < a[x][y])) {
        y = j;
      }
    }
    if (y == -1) {
      return vector<ld>(); // infeasible
    }
    pivot(x, y);
  }
  while (1) {
    int y = -1;
    for (int j = 1; j <= m; j++) {
      if (a[0][j] > eps && (y == -1 || a[0][j] > a[0][y])) {
        y = j;
      }
    }
    if (y == -1) {
      break;
    }
    int x = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i][y] > eps && (x == -1 || a[i][0] / a[i][y] < a[x][0] / a[x][y])) {
        x = i;
      }
    }
    if (x == -1) {
      return vector<ld>(); // unbounded
    }
    pivot(x, y);
  }
  vector<ld> ans(m + 1);
  for (int i = 1; i <= n; i++) {
    if (left[i] <= m) {
      ans[left[i]] = a[i][0];
    }
  }
  ans[0] = -a[0][0];
  return ans;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<ld>> mat(1 + m + n, vector<ld>(1 + m));
    vector<vector<int>> g(n);
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
      ++x; ++y;
      mat[m + x][i] = 1;
      mat[m + y][i] = 1;
      mat[i][i] = 1;
      mat[0][i] = 1;
      mat[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      mat[m + i][0] = 2;
    }
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
      deg[i] = int(g[i].size());
    }
    vector<int> rem(n, 2);
    int ans = 0;
    auto Dfs = [&](auto&& self, int cur) -> void {
      int min_ways = int(1e9);
      int who = -1;
      for (int i = 0; i < n; i++) {
        int actual_deg = 0;
        for (int j : g[i]) {
          actual_deg += int(rem[j] >= 1);
        }
        if (actual_deg > 0 && rem[i] > 0) {
          int ways = (actual_deg == 1 ? 1 : (rem[i] == 1 ? actual_deg : actual_deg * (actual_deg - 1) / 2));
          if (ways < min_ways) {
            min_ways = ways;
            who = i;
          }
        }
      }
      if (who == -1) {
        ans = max(ans, cur);
        return;
      }
      vector<int> nei;
      for (int x : g[who]) {
        if (rem[x] >= 1) {
          nei.push_back(x);
        }
        auto it = find(g[x].begin(), g[x].end(), who);
        g[x].erase(it);
      }
      assert(!nei.empty());
      auto old_g = g[who];
      g[who].clear();
      if (rem[who] == 1 || nei.size() == 1) {
        for (int x : nei) {
          rem[x] -= 1;
          self(self, cur + 1);
          rem[x] += 1;
        }
      } else {
        assert(rem[who] == 2 && nei.size() >= 2);
        for (int it = 0; it < int(nei.size()); it++) {
          for (int jt = it + 1; jt < int(nei.size()); jt++) {
            rem[nei[it]] -= 1;
            rem[nei[jt]] -= 1;
            self(self, cur + 2);
            rem[nei[it]] += 1;
            rem[nei[jt]] += 1;
          }
        }
      }
      g[who] = old_g;
      for (int x : g[who]) {
        g[x].push_back(who);
      }
    };
    Dfs(Dfs, 0);
    cout << ans << '\n';
  }
  return 0;
}
