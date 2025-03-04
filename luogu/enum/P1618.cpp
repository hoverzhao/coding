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

bool norepeat(int a, int b, int c) {
	set<int> s;
	if (b > 999 || c > 999) return false;
	int t=  0;
	while (a) { t = a % 10; if (t == 0) return false; s.insert(t); a /= 10; }
	while (b) { t = b % 10; if (t == 0) return false; s.insert(t); b /= 10; }
	while (c) { t = c % 10; if (t == 0) return false; s.insert(t); c /= 10; }
	if (s.size() == 9) return true;
	return false;
}

int main() {
	int a, b, c;
	int t1, t2, t3;
	int ans = 0;
	cin >> a >> b >> c;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			for (int k =1; k <= 9; k++) {
				t1 = i * 100 + j * 10 + k;
				if ((t1 * b) % a == 0 && (t1 * c) % a == 0) {
					 t2 = t1 / a * b;
					 t3 = t1 / a * c;
					 if (norepeat(t1, t2, t3)) {
						 cout << t1 << ' ' << t2 << ' ' << t3 << '\n';
						 ans++;
					 }
				}
			}
	if (ans == 0) 
		cout << "No!!!";
	return 0;
}

