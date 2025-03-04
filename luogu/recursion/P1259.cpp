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

string a[6];

int nn;
void step(string &s, int n) {
	if (n > 4) {
		cout << s << '\n';
		swap(s[n - 1], s[2*n]);
		swap(s[n], s[2*n + 1]);
		cout << s << '\n';
		swap(s[n - 1], s[2*n - 2]);
		swap(s[n], s[2*n - 1]);
		step(s, n - 1);
	} else {
		string ss;
		for (int i = 0; i < nn - 4; i++) {
			ss += "o*";
		}
		cout << a[0] + ss << '\n';
		cout << a[1] + ss << '\n';
		cout << a[2] + ss << '\n';
		cout << a[3] + ss << '\n';
		cout << a[4] + ss << '\n';
		cout << a[5] + ss << '\n';
	}

	
}

int main() {
	a[0] = "oooo****--";
	a[1] = "ooo--***o*";
	a[2] = "ooo*o**--*";
	a[3] = "o--*o**oo*";
	a[4] = "o*o*o*--o*";
	a[5] = "--o*o*o*o*";
	cin >> nn;
	string s, s1, s2;
	for (int i = 0; i < nn; i++) {
		s1 += 'o';
		s2 += '*';
	}
	s = s1 + s2 + "--";
	step(s, nn);
	return 0;
}

