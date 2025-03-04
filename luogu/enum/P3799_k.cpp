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

int b[10];
set<int> s;
bool isTrangle(int a, int b, int c) {
	return (a + b > c) && (b + c > a) && (a + c > b);
}

/* int t[5001][5001][5001]; */
bool isExist(int a, int b, int c) {
	/* if (t[a][b][c] == 1) return true; */
	/* t[a][b][c] = 1; */
	/* return false; */
	return false;
	/* int t = a * 100 + 10 * b + c; */
	/* if (s.find(t) == end(s)) {s.insert(t); return false;} */
	/* return true; */
}

vector<int> v;
int ans = 0;
void combination(int a[], int l, int r, int m) {
	for (int i = l; i <= r; i++) {
		b[l] = i;
		if (l > 0)
			combination(a, l - 1, i - 1, m);
		else {
			v.clear();
			for (int i = 0; i < m; i++) v.push_back(a[b[i]]);
			sort(v.begin(), v.end());
			if (isTrangle(v[0], v[1], v[2]) &&
				!isExist(v[0], v[1], v[2])) {
				ans++;
				/* for (int j = 0; j < m; j++) { cout << setw(3) << a[b[j]] ; } */
				/* cout << '\n'; */
			}
		}
	}
}

int a[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	combination(a, 3 - 1, n - 1, 3);
	cout << ans % (1000000000 + 7);
	return 0;
}

