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

string a[2000];

void cpy(int end) {
	for (int i = end; i < (end << 1); i++) {
		a[i] = a[i - end] + a[i - end];
	}
	for (int i = 0; i < end; i++) {
		a[i].insert(0, end, ' ');
		a[i].insert(a[i].length(), end, ' ');
	}

}

int main() {
	int n;
	cin >> n;
	a[0] = " /\\ ";
	a[1] = "/__\\";
	for (int i = 1; i < n; i++) cpy(1 << i);
	for (int i = 0; i < (1 << n); i++) cout << a[i] << '\n';

	return 0;
}

