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
char a[101][101];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j]; 
		}
	}
	int ans = 0;
	int con = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				con++; 
			} else if (a[i][j] == '#') {
				ans += (con - k >= 0) ? (con - k + 1) : 0;
				con = 0;
			}
		}
		//error 不可以放到for循环开始
		ans += (con - k >= 0) ? (con - k + 1) : 0;
		con = 0;
	}
	if (k == 1) {cout << ans; return 0; }
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i][j] == '.') {
				con++;
			} else if (a[i][j] == '#') {
				ans += (con - k >= 0) ? (con - k + 1) : 0;
				con = 0;
			}
		}
		ans += (con - k >= 0) ? (con - k + 1) : 0;
		con = 0;
	}
	/* cout << endl; */
	cout << ans;
	return 0;
}

