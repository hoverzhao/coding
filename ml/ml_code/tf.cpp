constexpr int md = int(1e9) + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);
 
Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
 
Mint F(int n, int m, int mx) {
  if (m < 0 || m > int64_t(mx) * n) {
    return 0;
  }
  int lim = min(n, m / mx);
  Mint ways = 0;
  for (int over = 0; over <= lim; over++) {
    int left = m - over * (mx + 1);
    if (left >= 0) {
      ways += C(n, over) * (over % 2 == 0 ? +1 : -1) * C(left + n - 1, left);
    }
  }
  return ways;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    Mint ans = 0;
    for (int mx = 1; mx <= m; mx++) {
      if (int64_t(mx) * n < m) {
        continue;
      }
      int lim = min(n, m / mx);
      if (lim == 0) {
        continue;
      }
      {
        Mint ways = F(n - 1, m - mx, mx);
        ans += ways * (mx - Mint(m - mx) / (n - 1));
      }
      if (n > 2) {
        Mint ways = F(n - 2, m - 2 * mx, mx);
        ans += ways * (n - 2) * (mx - Mint(m - 2 * mx) / (n - 2));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
