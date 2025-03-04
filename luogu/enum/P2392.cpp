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

/* int a[4][20]; */


int dp[2000];
int timecost(int b[], int n, int sum) {
	memset(dp, 0, sizeof(dp));
	int m = sum / 2; 
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= b[i]; j--) {
			dp[j] = max(dp[j], dp[j - b[i]] + b[i]);
		}
	}
	return sum - dp[m];
}

int a[22];
int s[4];
int sum[4];
int main() {
	for (int i = 0 ; i < 4; i++) cin >> s[i];
	int tt = 0;
	for (int k = 0; k < 4; k++) {
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= s[k]; i++) {
			cin >> a[i];
			sum[k] += a[i];
		}
		tt += timecost(a, s[k], sum[k]);
	}
	cout << tt;

	return 0;
}

