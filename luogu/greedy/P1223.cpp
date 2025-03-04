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

const int N = 1001;
struct pw {
	int index;
	int waittime;
}t[N];

int main() {
	int n;
	double totaltime = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i].waittime;
		t[i].index = i + 1;
	}
	auto cmp = [](const pw &a, const pw &b) {
		return a.waittime < b.waittime;
	};
	sort(t, t + n, cmp);
	int acc = 0;
	for (int i = 1; i < n; i++) {
		cout << t[i - 1].index << ' ';
		acc = acc + t[i - 1].waittime;
		totaltime += acc; 
	}
	cout << t[n - 1].index << '\n';
	cout << fixed << setprecision(2) << totaltime / n;
	return 0;
}

