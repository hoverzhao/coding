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

long long ans;
const int N = 1e5 + 5;
int a[N];

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (a[0] > x) { ans += a[0] - x; a[0] = x; }
	for (int i = 0; i < n; i++) {
		if (a[i] + a[i + 1] > x) {
			ans += a[i] + a[i + 1] - x;
			a[i + 1] = x - a[i];
		}
	}
	cout << ans;
	return 0;
}

