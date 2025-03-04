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

char graph[10][10];
int go[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
int d[10][10][10][10][4][4];

int main() {
	char c;
	int mi, mj; //人的位置
	int ci, cj; //牛的位置
	int mdir = 0, cdir = 0; //人和牛的方向
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> c;
			if (c == 'F') { mi = i; mj = j;}
			if (c == 'C') { ci = i; cj = j;}
			graph[i][j] = c;
		}
	}
	int step = 0; //步数
	for (;;) {
		if (mi == ci && mj == cj) { cout << step; break; }
		int mi_next = mi + go[mdir][0];
		int mj_next = mj + go[mdir][1];
		int ci_next = ci + go[cdir][0];
		int cj_next = cj + go[cdir][1];
		
		if (mi_next < 0 || mi_next >= 10 || mj_next < 0 || mj_next >= 10 || graph[mi_next][mj_next] == '*') { mdir = (mdir + 1) % 4;}
		else {
			mi = mi_next; mj = mj_next;
		}

		if (ci_next < 0 || ci_next >= 10 || cj_next < 0 || cj_next >= 10 || graph[ci_next][cj_next] == '*') { cdir = (cdir + 1) % 4;}
		else {
			ci = ci_next; cj = cj_next;
		}
		if (d[mi][mj][ci][cj][mdir][cdir]) { cout << 0 << '\n'; return 0;}
		else {d[mi][mj][ci][cj][mdir][cdir] = 1;}
		step++;
	}
	return 0;
}
