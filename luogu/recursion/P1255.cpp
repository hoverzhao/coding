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

int total;

int steps(int a) {
	if (a == 2) return 2;
	if (a == 1) return 1;
	return steps(a - 1) + steps(a - 2);
}

long long steps_o1(vector<long long> &book, int a) {
	/* if (a == 2 || a == 1) return a; */
	if (book[a]) return book[a];
	book[a] = steps_o1(book, a - 1) + steps_o1(book, a - 2);
	return book[a];
}

vector<vector<int>> vv(5001);

vector<int> hi_add(vector<int> a, vector<int> b) {
	if(a.size() < b.size()) return hi_add(b, a);
	vector<int> c; 
	int t = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		t += a[i];
		if (i < (int)b.size()) t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if (t) c.push_back(t);
	return c;
}

vector<int> steps_o2(vector<int> &book, int n) {
	if (book[n]) return vv[n];
	vv[n] = hi_add(steps_o2(book, n - 1), steps_o2(book, n - 2));
	book[n] = 1;
	return vv[n];
}

int main() {
	int n;
	cin >> n;

	//method 4. ---3 variant no recursion
	if ( n == 0 ) {cout << 0; return 0;}
	else if ( n == 1 ) {cout << 1; return 0;}
	else if ( n == 2 ) {cout << 2; return 0;}

	vector<int> sum, cur, prev;
	cur = vector<int> {2}; prev = vector<int> {1};
	for (int i = 3; i <= n; i++) {
		sum = hi_add(cur, prev);
		prev = cur;
		cur = sum;
	}
	int len = sum.size() - 1;
	while (len > 0 && sum[len] == 0) len--;
	while(len >= 0) cout << sum[len--];
	
	
	//method 3. pass
	/* if (n == 0) {cout << 0; return 0;} */
	/* vector<int> book(n + 1, 0); book[1] = 1; book[2] = 1; */
	/* vv[1] = vector<int> {1}; */
	/* vv[2] = vector<int> {2}; */
	/* vector<int> k = steps_o2(book, n); */
	/* int len = k.size() - 1; */
	/* while (k[len] == 0 && len > 0) len--; */
	/* while(len >= 0) cout << k[len--]; */

	// method 2. no pass
	/* cout << steps_o1(book, n); */
	// method 1. no pass
	/* cout << steps(n); */
	return 0;
}

