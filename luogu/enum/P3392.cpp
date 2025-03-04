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

void xprintf(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}
/* vector<vector<char>> a(n, vector<char>(m)); */
int n, m;
char a[51][51] {};
int b[4] {};
int result = INF;


int caculate(int c[]) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i < c[1]) {
			for (int j = 0; j < m; j++)
				if (a[i][j] != 'W') ans++;
		} else if (i >= c[1] && i < c[2]) {
			for (int j = 0; j < m; j++)
				if (a[i][j] != 'B') ans++;
		} else {
			for (int j = 0; j < m; j++)
				if (a[i][j] != 'R') ans++;
		}
	}
	return ans;
}

//在1-n个数,选p个数组合
void combination(int n, int m, int p) {
	for (int i = m; i <= n; i++) {
		b[m] = i;
		if (m > 1) {
			combination(i - 1, m - 1, p);
		} else {
			/* for (int j = 1; j <= p; j++) */
			/* 	cout << setw(3) << b[j]; */
			/* cout << '\n'; */ 
			result = min(result, caculate(b));
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	combination(n - 1, 2, 2);
	cout << result;

	// 排列问题 n 选3 ，一共有多少中排列方式
	return 0;
}

