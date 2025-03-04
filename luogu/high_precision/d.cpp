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

const int len = 10;
vector<int> ans(len, 0);

void caculate (int n) {
	do {
		for (int i = 0; i < len - 1; i++) {
			ans[i] = ans[i] * n;
		}
		for (int i = 0; i < len - 1; i++) {
			ans[i + 1] += ans[i] / 10;
			ans[i] = ans[i] % 10;
		}
	} while (--n);
}


int main() {
	int t;
	cin >> t;
	ans[0] = 1;
	while (t--) {
		int n, a;
		cin >> n >> a;
		fill(ans.begin(), ans.end(), 0);
		ans[0] = 1;
		caculate(n);
		int k = len - 1;
		while (ans[k] == 0 && k > 0) k--;
		int end = k;
		while (k >= 0) {cout << ans[k]; k--;}
		/* while (k >= 0) {k--;} */
		int t = count(ans.begin(), ans.begin() + end + 1, a);
		cout << t << '\n';
	}
	return 0;
}

