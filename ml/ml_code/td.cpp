vector<int> lf(n);
vector<int> nei(n);
for (int i = 0; i < n; i++) {
  if (g[i].size() == 1) {
	lf[g[i][0]] += 1;
  }
}
for (int i = 0; i < n; i++) {
  if (g[i].size() > 1) {
	for (int j : g[i]) {
	  if (j > i && g[j].size() > 1) {
		nei[i] += 1;
		nei[j] += 1;
	  }
	}
  }
}
int mx = *max_element(nei.begin(), nei.end());
if (mx > 2) {
  cout << 0 << '\n';
  continue;
}
Mint ans = (mx == 0 ? 2 : 4);
C(n, 0);
for (int i = 0; i < n; i++) {
  ans *= fact[lf[i]];
}
cout << ans << '\n';
}
return 0;
