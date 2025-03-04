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

void xprintf(int a[], int l, int r) {
	for (int i = l; i <= r; i++)
		cout << a[i] << ' ';
	cout << '\n';
}
//  快排 三路分区去重复
void quicksort_3way(int a[], int l, int r) {
	if (l >= r) return;
	/* xprintf(a, l, r); */
	
	int last = l + (r - l) / 2;
	swap(a[last], a[r]);

	last = l;		 //    <        =		 >
	int e = l;		 //  l----last-------e------r
	for (int i = l; i < r; i++) {
		if (a[i] < a[r]) {
			swap(a[last], a[i]);
			if (e != last)
				swap(a[e], a[i]);
			e++; last++;
			 
		} else if(a[i] == a[r]) {
			swap(a[e], a[i]);
			e++;
		}
		/* dbg(last, e); */
		/* xprintf(a, l, r); */
	}
	/* dbg(last, e); */
	/* xprintf(a, l, r); */
	/* printf("********\n"); */
	swap(a[e], a[r]);
	/* xprintf(a, l, r); */
	quicksort_3way(a, l, last - 1);
	quicksort_3way(a, e + 1, r);
}

int b[100];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	quicksort_3way(b, 0, n - 1);
	/* quicksort1(b, 0, n - 1); */
	/* optimize_quicksort(b, 0, n - 1); */

	for (int i = 0; i < n; i++) cout << b[i] << ' ';
	return 0;
}

