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

// 递归超时
/* int cnt = 0; */
/* void dfs(int n) { */
/* 	if (n == 0) return ; */
/* 	cnt++; */
/* 	for (int i = n / 2; i > 0; i--) { */
/* 		dfs(i); */
/* 	} */
/* } */
int f[1100];
int main() {
	int n;
	cin >> n;
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0)
			f[i] = f[i - 1] + f[i / 2];
		else 
			f[i] = f[i - 1];
	}
	cout << f[n];
	/* dfs(n); */
	/* cout << cnt; */
	return 0;
}

