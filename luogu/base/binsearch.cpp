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
	freopen("binsearch.in", "r", stdin);
	freopen("binsearch.out", "w", stdout);
	return 0;
}();


using ll = long long;
using lld = long double;
const int INF = 1e9;
const long long LINF = 1e18;

vector<int> a;
//2 3 4 5 5 5 5 5 5 8 9
// 1
int main() {
	int n;
	cin >> n;
	vector<int> a(
	return 0;
}

