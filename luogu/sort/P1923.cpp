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
	/* freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout); */
#endif
	return 0;
}();

/* #define LINF 0x3f3f3f3f3f3f3f3f */
#define INF  0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef long double ld;

void xprintf(int a[], int l, int r) {
	for (int i = l; i <= r; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

void shiftdown(int a[], int id, int len) {
	while (id * 2 <= len) {
		int l = id * 2;
		int r = id * 2 + 1;
		int t = a[l] > a[id] ? l : id;
		if (r <= len && a[r] > a[t]) t = r;
		if (t != id) {
			swap(a[t], a[id]);
			id = t;
		} else break;
	}
}

void createheap(int a[], int len) {
	int now = len / 2;
	for (int i = now; i >= 1; i--) {
		shiftdown(a, i, len);
	}
}

int a[5000001];
int main() {
	int n, k; 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	createheap(a, k + 1);

	for(int i = k + 2;  i <= n; i++) {
		if (a[i] >= a[1]) continue;
		a[1] = a[i];
		shiftdown(a, 1, k + 1);
	}
	cout << a[1];
	return 0;
}

