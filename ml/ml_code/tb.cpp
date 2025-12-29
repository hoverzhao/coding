int ans = -1;
for (int rot = 0; rot < 2; rot++) {
  int L = 1;
  int R = n - x;
  for (int i = x - 1; i >= 0; i--) {
	if (s[i] == '#') {
	  L = i + 2;
	  break;
	}
  }
  ans = max(ans, min(L, R));
  reverse(s.begin(), s.end());
  x = n - 1 - x;
}
