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

int main() {
	long long ans = 0;
	int n;
	cin >> n;
	/* vector<long long> a {4, 3, 2, 5, 1}; */
	/* sort(a.begin(), a.end(), std::less<long long>()); */
	/* dbg(a); */

	priority_queue<long long, vector<long long>, std::greater<long long> > q;
	for (int i = 0; i < n; i++) {
		int t = 0; cin >> t;
		q.push(t);
	}
	/* while (!q.empty()) { cout << q.top() << ' '; q.pop(); } */
	long long s; 
	while (!q.empty() && q.size() > 1) {
		s = q.top(); q.pop();
		s += q.top(); 
		ans += s;
		q.pop(); 
		q.push(s);
	}


	// error: time limit exceed
	/* sort(a.begin(), a.end(), std::less<long long>()); */
	/* for (int i = 1; i < n; i++) { */
	/* 	a[i] += a[i - 1]; */
	/* 	ans += a[i]; */
	/* 	sort(a.begin() + i, a.end(), std::less<long long>()); */
	/* } */
	cout << ans;
	return 0;
}

