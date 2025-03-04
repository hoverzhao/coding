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

int dp[10000];
int a[101];
int main() {
	//0 1 背包问题
	int m, n = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {cin >> a[i];}
	//没钱，不点菜也是一种方法 j == a[i] 的情况
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= a[i]; j--) {
			dp[j] = dp[j] + dp[j - a[i]];
		}
		/* for (int i = 0; i <= n; i++) { */
		/* 	cout << dp[i] << ' '; */
		/* } */
		/* cout << '\n'; */
	}	
	cout << dp[m];
	return 0;
}

