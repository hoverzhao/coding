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

int f[1000005];
int g[1000005];
int main() {
	int n;
	cin >> n;
	//递推公式
	//f[n] = f[n - 1] + f[n - 2] + 2 * g[n - 2]
	//g[n - 2] = f[n - 3] + g[n - 3]
	//f[1] = 1	
	//f[2] = 2 = f[0] + f[1]   ==> f[0] = 1		==>g[0] = 0
	//f[3] = 5 = f[1] + f[2] + 2 * g[3 - 2]      ==> g[1] = 1
	f[0] = 1; f[1] = 1; f[2] = 2;
	g[0] = 0; g[1] = 1;
	for (int i = 3; i <= n; i++) {
		g[i - 2] = (g[i - 3] + f[i - 3]) % 10000;
		f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 2]) % 10000;
	}
	cout << f[n];
	return 0;
}

