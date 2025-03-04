#include <bits/stdc++.h>

#define ll	long long
#define INF 0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();

int s[9][9] = {};

int main() {
	int n;
	cin >> n;
	int k = 2;
	int i = 0, j = 0;
	s[0][0] = 1;
	while ( k <= n * n) {
		while (j < n-1 && s[i][j + 1] == 0) s[i][++j] = k++;
		while (i < n-1 && s[i + 1][j] == 0) s[++i][j] = k++;
		while (j > 0 && s[i][j - 1] == 0) s[i][--j] = k++;
		while (i > 0 && s[i - 1][j] == 0) s[--i][j] = k++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setfill(' ') << setw(3) << s[i][j];
		cout << endl;
	}

	return 0;
}

