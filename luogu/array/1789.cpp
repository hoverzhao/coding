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

int s[100][100] = {};
int n, m, k;

void mklight(int y, int x, bool bstone) {
	for (int row = x - 2; row <= x + 2; row++)
		for(int col = y - 2; col <= y + 2; col++) {
			if (row >= 0 && row < n && col >= 0 && col < n) {
				if (bstone) {
					s[row][col] = 1;
				} else {
					if (abs(abs(x - row) + abs(y - col)) <= 2)
						s[row][col] = 1;
				}
			}
		}
}

int main() {
	cin >> n >> m >> k;
	int x, y;
	while (cin >> x >> y) {
		if (m-- > 0) {
			//大坑 输入坐标从1，1开始的
			mklight(y - 1, x - 1, false);
		}
		else
			//注意，x为列号，y为行号
			mklight(y - 1, x - 1, true);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for(int j =0; j < n; j++) {
			if (s[i][j] == 0) 
				ans++;
			/* cout << setw(1) << s[i][j] << ' '; */
		}
		/* cout << endl; */
	}
	cout << ans;

	return 0;
}


