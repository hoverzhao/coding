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

int go[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};

char graph[10][10];

int main() {
	char c;
	int im, jm;
	int ic, jc;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> c;
			if (c == 'F') { im = i; jm = j;}
			if (c == 'C') { ic = i; jc = j;}
			graph[i][j] = c;
		}
	}
	int imstart = im, jmstart = jm;
	int icstart = ic, jcstart = jc;
	int step = 0;
	int dir = 0;
	int cdir = 0;
	for (;;) {
		if (im == ic && jm == jc) { cout << step; break; }
		int in = im + go[dir][0];
		int jn = jm + go[dir][1];
		int icn = ic + go[cdir][0];
		int jcn = jc + go[cdir][1];
		
		if (in < 0 || in >= 10 || jn < 0 || jn >= 10 || graph[in][jn] == '*') { dir = (dir + 1) % 4;}
		else {
			im = in; jm = jn;
		}

		if (icn < 0 || icn >= 10 || jcn < 0 || jcn >= 10 || graph[icn][jcn] == '*') { cdir = (cdir + 1) % 4;}
		else {
			ic = icn; jc = jcn;
		}

		if (im == imstart && jm == jmstart && ic == icstart && jc == jcstart && !dir && !cdir) {cout << 0 << endl; return 0;}
		step++;
		
	}
	return 0;
}
