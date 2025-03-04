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
	string na;
	int k;
	cin >> na >> k;
	int len = (int)na.size();

	char t = na[0];
	//扫描线
	int line = 0;
	int s = 0;
	while (k > 0) {
		for (int i = line; i <= min(k + line ,len - 1); i++) {
			s = line;
			t = na[line];
			/* cout << "t:" << t << '\n'; */
			/* cout << "i:" << i << ' '; */
			/* cout << "line:" << line << ' ' << '\n'; */
			if (t > na[i]) {
				t = na[i];
				line = i;
			}
		}
			cout << "k + line:" << k + line << '\n';
			/* cout << "line:" << line << ' ' << '\n'; */
			cout << na[line++] << '\n' ;
			k -= line - s;
	}
	return 0;
}

