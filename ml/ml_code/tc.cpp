   for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        swap(a[i], b[i]);
      }
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    int mn = int(1.01e9);
    for (int i = 0; i < n - 1; i++) {
      mn = min(mn, a[order[i + 1]] - b[order[i]]);
    }
    mn = max(mn, 0);
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      ans += b[i] - a[i];
    }
    ans += 2 * mn;
    cout << ans << '\n';
