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

string run(int n, int i = 0) {
	if(n == 0) return "0";
	string s = "";
	do 
		if(n & 1) 
			s = (i == 1 ? "2" : "2(" + run(i)+ ")" )
				+ (s == "" ? "" : "+")
				+ s;
	while(++i, n >>=1);
	return s;
}

// 3 = 2 + 2^0
// 6 = 2^2 + 2
// 7 = 2^2 + 2 + 2^0
int main() {
	int n; cin >> n;
	cout << run(n) << '\n';
	return 0;
}

