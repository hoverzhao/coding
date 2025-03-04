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


int n;
int high = -1;
bool isend = false;

string procExp(int exp) {
	if (exp == 0) return "";
	if (exp == 1) return "x";
	return "x^" + to_string(exp);
}

string procCoef(int coef) {
	string s;
	if (coef == 0) return "";
	if (coef == -1 && !isend) return "-";
	if (coef == 1 && !isend) return "+";
	return coef > 0 ? "+" + to_string(coef) : to_string(coef);
}
/* 100x^5-x^4+x^3-3x^2+10 */
string genStr(int exp, int coef) {
	string s;
	string sc = procCoef(coef);
	s = sc.empty() ? sc : procCoef(coef) + procExp(exp);
	if (exp == high && coef > 0) {
		s.erase(0, 1);
	}
	return s;
}

int main() {
	cin >> n;
	int t;
	int exp = n;
	string out = "";
	bool ishigh = false;
	while (cin >> t) {
		if (n == 0) { cout << t; return 0;}
		if (!ishigh && t != 0) {high = exp; ishigh = true;}
		if (exp == 0) {isend = true;}
		out += genStr(exp--, t);
	}
	cout << out;
	return 0;
}

