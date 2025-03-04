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


void xprintf(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}
// n个不同的数，取其中m个数, 一共多少种取法
/* 1. 选择第i（m <=i<=n）个元素作为每个组合的最后元素，在第1————i个元素中往前（前i - 1个元素中）选取m-1个元素。 */
/* 2. 若m等于1（对应b[0]），则表示选完，输出该组合（数组b中存储的是组合的元素在a中的下标） */
/* 3. 若m>1，则重复1、2步骤 */

int b[30];
int book[30];
void back_combination(int n, int m, int pick) {
	for (int i = m; i <= n; i++) {
		b[m - 1]  = i - 1;
		if (m > 1 ) {
			back_combination(i - 1, m - 1, pick);
		} else {
			for (int j = 0; j < pick; j++) {
				cout << setw(3) << b[j] + 1 ; 
			}
			cout << '\n';
		}
	}
}
//按字典序输出
void front_combination(int n, int m, int k, int pick) {
	if ( k > m) {
		for (int i = 1; i <= m; i++) {
			cout << setw(3) << b[i] ;
		}
		cout <<'\n';
		return;
	}
	for (int i = b[k - 1] + 1; i <= n; i++) {
		b[k] = i;
		front_combination(n, m, k + 1, pick);
	}
}

//排列递归解法
void permutation(int n, int k) {
	if (k > n) {
		for (int i = 1; i <= n; i++) { cout << setw(5) << b[i]; }
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if(book[i]) continue;
		book[i] = 1;
		b[k] = i + 1;
		permutation(n, k + 1);
		book[i] = 0;
	}
	return ;
}

//全排列stl解法

int main() {
	/* int n, r; */
	/* cin >> n >> r; */
	/* back_combination(n, r, r); */
	/* front_combination(n, r, 1, r); */
	int n;
	cin >> n;
	permutation(n, 1);

	/* vector<int> a(n, 0); */
	/* for (int i = 0; i < n; i++) { a[i] = i + 1; } */
	/* do { */
	/* 	for (int i = 0; i < n; i++) { cout << setw(5) << a[i]; } */
	/* 	cout << '\n'; */
	/* } while (next_permutation(a.begin(), a.end())); */
	return 0;
}
