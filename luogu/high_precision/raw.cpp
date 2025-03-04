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

// 通用函数
// 读取

string s;

void common() {
	for (int i = s.size() - 1; i >= 0; i--) { a.emplace_back(s[i] - '0');}
}

bool cmp(const vector<int> &a, const vector<int> &b) {
	if (a.size() != b.size()) 
		return a.size() < b.size();

	for (int i = a.size() - 1; i >= 0; i--) 
		if (a[i] != b[i]) 
			return a[i] < b[i];
	return false;
}

vector<int> add(const vector<int> &a, const vector<int> &b) {
	if (a.size() < b.size()) return add(b, a);
	vector<int> c;
	int t = 0; // 进位
	for (int i = 0; i < a.size(); i++) {
		t += a[i];
		if (i < b.size()) t += b[i];
		c.emplace_back(t % 10);
		t /= 10;
	}
	if (t) c.emplace_back(t);
	return c;
}

vector<int> sub(const vector<int> &a, const vector<int> &b) {
	int t = 0; // 借位
	vector<int> c;
	for (int i = 0; i < a.size(); i++) {
		t = a[i] - t;
		if (i < b.size()) t -= b[i];
		c.emplace_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	while (c.size() > 0 && c.back() == 0) c.pop_back();
	return c;
}

vector<int> mul(const vector<int> &a, int b) {
	int t = 0; // 进位
	for (i = 0; i < a.size() || t; i++) {
		if ( i < a.size()) t += a[i] * b;
		c.emplace_back(t % 10);
		t /= 10;
	}
	while (c.size() > 0 && c.back() == 0) c.pop_back();
	return c;
}

