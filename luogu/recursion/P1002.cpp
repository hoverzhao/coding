#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "*" << #x << " -> "; err(x); } while (0)
void err() {cout << endl; }
template<template<typename...> class T, typename t, typename...A>
void err(T<t> a, A... x) { for (auto v : a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();

/* #define LINF 0x3f3f3f3f3f3f3f3f */
#define INF  0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef long double ld;

int tx, ty, hx, hy ;
long long cnt;
vector<int> vx, vy;

struct pptt {
	int x;
	int y; 
};

deque<pptt> q;
vector<vector<long long> > dst;

void printx() {
	for (int i = 0; i <= tx; i++) {
		for (int j = 0; j <= ty; j++) {
			cout << dst[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void printy(int cx, int cy) {
	fill(dst.begin(), dst.end(), vector<long long>(ty + 1, 0));
	for (int i = 0; i <= tx; i++) {
		for (int j = 0; j <= ty; j++) {
	if ((abs(i - cx) == 2 && abs(j - cy) == 1) ||
	    (abs(i - cx) == 1 && abs(j - cy) == 2))
			dst[i][j] = 8;
		}
		cout << '\n';
	}
	cout << '\n';
}

bool paths(int cx, int cy) {
	if (cx > tx || cy > ty) { return false; }
	if ((abs(hx - cx) == 2 && abs(hy - cy) == 1) ||
	    (abs(hx - cx) == 1 && abs(hy - cy) == 2) ||
		(cx == hx && cy == hy)) { return false; }
	if (cx == tx && cy == ty) { cnt++; printx(); return false; }

	dst[cx][cy] = 1;
	paths(cx + 1, cy);
	paths(cx, cy + 1);
	dst[cx][cy] = 0;
	return true;
}


int main() {
	cin >> tx >> ty >> hx >> hy;
	/* vector<vector<int>> dd(tx + 1, vector<int>(ty + 1)); */ 
	/* dst = dd; */
	//传统递归实现 超时超内存
	/* paths(0, 0); */
	/* cout << cnt; */
	//dp实现
	//dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	vector<vector<long long>> dst(tx + 1, vector<long long>(ty + 1, 0)); 
	dst[0][0] = 1;

	for (int i = 0; i <= tx; i++) {
		for (int j = 0; j <= ty; j++) {
			if ((abs(hy - j) == 2 && abs(hx - i) == 1) ||
					(abs(hy - j) == 1 && abs(hx - i) == 2) ||
					(i == hx && j == hy)) { 
				dst[i][j] = 0; continue;
			}
			if (i)
				dst[i][j] += dst[i - 1][j];
			if (j)
				dst[i][j] += dst[i][j - 1];
		}
	}

	cout << dst[tx][ty];


	return 0;
}

