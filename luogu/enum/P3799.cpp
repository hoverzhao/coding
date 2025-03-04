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
const int mod = 1e9 + 7;

int a[5001];

int comb(int n, int k) {
	if (k == 1) return n % mod;
	return (n * (n - 1) / 2) % mod;
}

void xprintf(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}
int main() {
	int n;
	int mm = INF, mx = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (mm > t) mm = t;
		if (mx < t) mx = t;
		a[t]++;
	}
	int ot = 0;
	int sum = 0;
	for (int i = mm; i <= mx; i++) {
		if (a[i] >= 2) {
			ot = comb(a[i], 2);
			for (int j = mm; j <= i / 2; j++) {
				if (j == i - j && a[j] >= 2) {
					sum = (sum + ot * comb(a[j], 2)) % mod;
				}
				if (j != i - j && a[j] >= 1 && a[i - j] >= 1) {
					sum = (sum + ot * comb(a[j], 1) * comb(a[i - j], 1)) % mod;
				}
			}
		}
	}
	cout << sum;
	
	return 0;
}


