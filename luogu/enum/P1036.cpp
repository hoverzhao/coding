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


int total = 0;
int pick = 0;
int a[20];
int b[20];
int ans = 0;

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}
void xprintf(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}
// n个不同的数，取其中m个数, 一共多少种取法
/* 1. 选择第i（m <=i<=n）个元素作为每个组合的最后元素，在第1————i个元素中往前（前i - 1个元素中）选取m-1个元素。 */
/* 2. 若m等于1（对应b[0]），则表示选完，输出该组合（数组b中存储的是组合的元素在a中的下标） */
/* 3. 若m>1，则重复1、2步骤 */
void combination(int n, int m) {
	int i, j, sum = 0;
	for (i = m; i <=n; i++) {
		b[m - 1] = i - 1;
		if (m > 1)
			combination(i - 1, m - 1);
		else {
			/* xprintf(a, total); */
			/* cout << '\n'; */
			sum = 0;
			for (j = 0; j < pick; j++) {
				sum += a[b[j]];
			}
			/* cout << "sum= " << sum << "pick= " << pick << endl; */
			if (isPrime(sum))
				ans++;
		}
	}
	/* cout << "**** " << '\n'; */
}


int main() {
	cin >> total >> pick;
	for (int i = 0; i < total; i++) {
		cin >> a[i];
	}
	combination(total, pick);
	/* int n; */
	/* cin >> n; */
	/* for (int i = 0 ; i < n; i++) { */
	/* 	cin >> a[i]; */ 
	/* } */
	cout << ans;
	return 0;
}

