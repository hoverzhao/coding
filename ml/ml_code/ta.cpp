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
	int mx = *max_element(a.begin(), a.end());
	if (mx == -1) {
	  cout << "YES" << '\n';
	  continue;
	}
	bool ok = (mx > 0);
	for (int i = 0; i < n; i++) {
	  ok &= (a[i] == -1 || a[i] == mx);
	}
	cout << (ok ? "YES" : "NO") << '\n';
}
return 0;
