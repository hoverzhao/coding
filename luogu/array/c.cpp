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

int n;
int nc = 1;
int s[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int book[9][9] = {};
int a[9][9] = {};

void setm(int row, int col, int ndir) {
	if ( nc >= n * n ) return;
	ndir = ndir % 4;

	row += s[ndir][0];
	col += s[ndir][1]; 

	for (;row < n && row >= 0 && col >= 0 && col < n && book[row][col] != 1;
			row += s[ndir][0], col += s[ndir][1]) { 

		a[row][col] = ++nc;
		book[row][col] = 1;
	}
	setm(row - s[ndir][0], col - s[ndir][1], ndir + 1);
}

int main() {
	cin >> n;
	a[0][0] = 1;
	book[0][0] = 1;
	setm(0, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(3) << setfill(' ') << a[i][j];
		cout << endl;
	}
	return 0;
}

	
