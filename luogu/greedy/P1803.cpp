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

struct match {
	int l;
	int r;
	int operator < (match b) {
		if (r == b.r) return l < b.l;
		return r < b.r;
	}
}a[1000001];

int main() {
	int n, ans = 0;
	cin >> n;
	//左端点排序，错误 如下
	// |——————————————————|
	//      |————|  |—————|
	//按时间长短排序，错误，例如
	//		|———|
	//|——————| |————|
	//结束紧接着开始，也不行
	
	//按右端点优先排序，左端点第二优先级（从小到大排序最快)
	for (int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].r;
	}
	auto cmp = [](const match &a, const match &b) {
		if (a.r == b.r) return a.l < b.l;
		return a.r < b.r;
	};
	sort(a, a + n, cmp);
	/* sort(a, a + n); */
	int line = - 1;
	for (int i = 0; i < n; i++) {
		if (line <= a[i].l) {
			ans++;
			line = a[i].r;
		}
	}
	cout << ans;

	return 0;
}

