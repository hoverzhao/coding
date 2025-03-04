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

const int N = 101;

struct goldheap {
	double m;
	double v;
	double average;
}G[N];

int main() {
	int n, t;
	double ans = 0.0;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> G[i].m >> G[i].v;
		G[i].average = (double)G[i].v / G[i].m;
	}

	auto cmp = [](const goldheap &a, const goldheap &b) {
		return a.average > b.average;
	};

	sort(G, G + n, cmp);
	for (int i = 0; i < n && t; i++) {
		if (t >= G[i].m) {
			ans += G[i].v;
			t -= G[i].m;
		} else {
			ans += G[i].average * t;
			t = 0;
		}
	}
	cout << fixed << setprecision(2) <<  ans;
	return 0;
}

