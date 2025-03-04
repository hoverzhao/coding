#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();


int v[501][501];
int vt[501][501];

void magicmat(int x, int y, int r, int z) {
	//计算左上角位置
	memset(vt, 0, sizeof(vt));
	int x0 = x - r; int y0 = y - r; 
	int n = 2 * r + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//顺时针
			if (z == 0) {
				vt[j][n - i - 1] = v[x0 + i][y0 + j];
			} else {
				vt[n - j - 1][i] = v[x0 + i][y0 + j];
			}
		}
	}

	for (int i = 0; i <  n ; i++)
		for (int j = 0; j <  n; j++)
			v[x0 + i][y0 + j] = vt[i][j];
}

int main() {
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) { v[i][j] = n * i + j + 1; vt[i][j] = 0; }

	/* for (int i = 0; i < n; i++) { */
	/* 	for (int j = 0; j < n; j++) { */
	/* 		cout << setw(2) << v[i][j] << ' '; */
	/* 	} */
	/* 	cout << '\n'; */
	/* } */
	/* cout << "********" << endl; */

	//注意题目是x行,y列，不是坐标x, y
	while (m--) {
		int x, y, r, z;
		cin >> x >> y >> r >> z;
		magicmat(x - 1 , y - 1 , r, z);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			/* cout << setw(2) << v[i][j] << ' '; */
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}

