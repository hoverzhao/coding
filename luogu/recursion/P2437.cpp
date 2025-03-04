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

int dp[1005];


vector<int> hi_add(vector<int> &a, vector<int> &b) {
	if (a.size() < b.size()) return hi_add(b, a);
	vector<int> c;
	int t = 0; int len = (int)a.size();
	for (int i = 0; i < len; i++) {
		t += a[i];
		if (i < (int)b.size()) t +=b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if (t) c.push_back(t);
	return c;
}


int main() {
	int m, n;
	cin >> m >> n;
	if (n == 1 || n == 2) cout << 1;
	vector<vector<int>> dp(n + 1);
	dp[n] = vector<int> {1};
	dp[n - 1] = vector<int> {1};
	dp[n - 2] = vector<int> {2};
	for (int i = n - 3; i > 0 && i >= m; i--) {
		dp[i] = hi_add(dp[i + 1], dp[i + 2]);
	}
	int len = (int)dp[m].size();
	while (len > 0) cout << dp[m][--len];
	//整数溢出
	/* if (n == 1 || n == 2) cout << 1; */
	/* dp[n] = 1; */
	/* dp[n - 1] = 1; */
	/* dp[n - 2] = 2; */

	/* for (int i = n - 3; i > 0 && i >= m; i--) { */
	/* 	dp[i] = dp[i + 1] + dp[i + 2] ; */
	/* 	/1* printf("dp[%d] = %d \n", i, dp[i]); *1/ */
	/* } */
	/* cout << dp[m]; */
	return 0;
}

