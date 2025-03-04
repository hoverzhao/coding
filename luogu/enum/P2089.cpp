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

int n = 0;
vector<int> a(10);
vector<vector<int>> ans;

void dfs(int pos, int sum) {
	if (pos == 10 || sum > n) {
		if (sum == n) {
			ans.push_back(a);
		}
		return;
	}

	for (int i = 1; i <=3; i++) {
		a[pos] = i;
		dfs(pos + 1, sum + i);
	}
}

int main() {
	cin >> n;
	dfs(0, 0);
	cout << ans.size() << '\n';
	for (auto v : ans) {
		for (auto t : v)
			cout << t << ' ';
		cout << '\n';
	}
	return 0;
}

