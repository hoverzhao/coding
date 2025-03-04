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

const int maxlen = 1000;
vector<int> a(maxlen, 0);
vector<int> b(maxlen * 2 + 1, 0);
vector<int> c(maxlen * 2 + 1, 0);
int la, lb, lc;

void himul1() {
	/* cout << "himul1 \n"; */
	std::fill(b.begin(), b.end(), 0);
	for (int i = 0; i < la; i++) {
		for (int j = 0; j < lc; j++) {
			b[i + j] += a[i] * c[j];
			b[i + j + 1] += b[i + j] / 10;
			b[i + j] %= 10;
		}
	}
	lb = la + lc;
	lb = lb > 500 ? 500 : lb;
	while (b[lb] == 0 && lb != 0) lb--;
	lc = ++lb;
	std::copy(b.begin(), b.end(), c.begin()); 
	/* dbg(c); */
}

void himul2() {
	/* cout << "himul2 \n"; */
	std::fill(b.begin(), b.end(), 0);
	for (int i = 0; i < la; i++) {
		for (int j = 0; j < la; j++) {
			b[i + j] += a[i] * a[j];
			b[i + j + 1] += b[i + j] / 10;
			b[i + j] %= 10;
		}
	}
	lb = la + la ;
	lb = lb > 500 ? 500 : lb;
	while (b[lb] == 0 && lb != 0) lb--;
	la = ++lb;
	std::copy(b.begin(), b.end(), a.begin());
	/* dbg(a); */
}


int main() {
	int p;
	cin >> p ;
	cout << (int)(log10(2) * p + 1) << '\n';
	a[0] = 2;
	c[0] = 1;
	la = 1; lb = 2; lc = 2;
	while (p) {
		if (p & 1) himul1();
		himul2();
		p >>= 1;
	}
	c[0]--;
	/* dbg(c); */
	int i = 500, j = 0;
	while(i--) {
		if (j >= 50) {
			j = 0; 
			cout << '\n';
		}
		j++;
		cout << c[i];
	}
	
	return 0;
}
