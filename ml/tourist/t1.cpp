int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
      pref[i] = min(pref[i - 1], a[i]);
    }
    vector<int64_t> sum_pref(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      sum_pref[i] = sum_pref[i + 1] + pref[i];
    }
    vector<int64_t> ans(n);
    ans[0] = sum_pref[0];
    vector<int> who(n + 1);
    int last = -1;
    for (int i = n - 1; i >= 0; i--) {
      while (a[i] > last) {
        last += 1;
        who[last] = i;
      }
    }
    vector<int> mins;
    int mn = int(1e9);
    for (int i = 0; i < n; i++) {
      if (a[i] < mn) {
        mn = a[i];
        mins.push_back(i);
      }
    }
    vector<int> b(n);
    LazySegmentTree<Info, Tag> st(n);
    vector<tuple<int, int, int>> ops;
    ops.reserve(2 * n);
    for (int it = 0; it < int(mins.size()); it++) {
      int i = mins[it];
      int lim = (i == 0 ? a[i] + n : pref[i - 1]);
      int until = (it == int(mins.size()) - 1 ? n : mins[it + 1]);
      int fake_mn = lim;
      for (int k = i; k < until; k++) {
        if (k > i) {
          fake_mn = min(fake_mn, a[k]);
        }
        b[k] = fake_mn - a[i];
      }
      int ptr = until;
      for (int x = 0; x <= b[i]; x++) {
        int j = who[x];
        if (j <= i) {
          break;
        }
        int64_t val = sum_pref[0] + st.Query(i, j).sum - sum_pref[j];
        ans[j - i] = max(ans[j - i], val);
        while (ptr > i && b[ptr - 1] <= x) {
          ptr -= 1;
        }
        if (ptr > i) {
          st.Modify(i, ptr, {+1});
          ops.emplace_back(i, ptr, +1);
        }
      }
      while (!ops.empty()) {
        auto [A, B, C] = ops.back();
        st.Modify(A, B, {-C});
        ops.pop_back();
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
