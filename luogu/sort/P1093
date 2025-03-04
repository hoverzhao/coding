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

struct stu {
	int id;
	int liter;
	int math;
	int eng;
	int total;
};
int main() {
	int n;
	cin >> n;
	vector<stu> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].liter >> a[i].math >> a[i].eng;
		a[i].id = i + 1;
		a[i].total = a[i].liter + a[i].math + a[i].eng;
	}
	auto cmp = [](const stu &a, const stu &b) {
		if (a.total > b.total) return true;
		if (a.total == b.total) {
			if (a.liter > b.liter) return true;
			if (a.liter == b.liter) {
				if (a.id < b.id) return true;
			}
		}
		return false;
	};
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < 5; i++)
		cout << a[i].id << ' ' << a[i].total << '\n';
	return 0;
}

