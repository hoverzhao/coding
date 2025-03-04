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

void xprintf(int a[], int l, int r) {
	for (int i = l; i <= r; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

//快排基础实现 方法一
void quicksort_ij(int a[], int l, int r) {
	if (l >= r) return;
	int i = l - 1, j = r;
	int p = a[r];

	while (i < j) {			//								   p
		while (a[++i] < p); //为什么不能用 <= 号? 11 10 8 7 12 13
		while (a[--j] > p) {if (j == i) break;} //避免越界问题
		if (i < j)
			swap(a[i], a[j]);
	}
	swap(a[r], a[i]);
	quicksort_ij(a, l, i - 1);
	quicksort_ij(a, i + 1, r);
}

// 快排基础实现 方法二	
void quicksort_l(int a[], int l, int r) {
	if (l >= r) return;
	
	int last = l + (r - l) / 2;
	swap(a[last], a[l]);
	last = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < a[l])
			swap(a[++last], a[i]);
	}
	swap(a[last], a[l]);
	quicksort_l(a, l, last - 1);
	quicksort_l(a, last + 1, r);
}

// 快排基础实现 方法三	
void quicksort_r(int a[], int l, int r) {
	if (l >= r) return;
	
	int last = l + (r - l) / 2;
	swap(a[last], a[r]);
	last = l;
	for (int i = l; i <= r; i++) {
		if (a[i] < a[r])
			swap(a[last++], a[i]);
	}
	swap(a[last], a[r]);
	quicksort_r(a, l, last - 1);
	quicksort_r(a, last + 1, r);
}


// 快排优化

const int CUTOFF = 10;
void insertsort(int a[], int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		int t = a[i]; int j;
		for (j = i; j > l && t < a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = t;
	}
}

int median3(int a[], int l, int r) {
	int mid = l + (r - l) / 2;
	if (a[l] > a[mid])	swap(a[l], a[mid]);
	if (a[l] > a[r])	swap(a[l], a[r]);
	if (a[mid] > a[r])	swap(a[mid], a[r]);
	swap(a[mid], a[r - 1]); //移动到倒数第二位
	return a[r - 1];
}

void optimize_quicksort(int a[], int l, int r) {
	if (l + CUTOFF < r) {
		int i = l, j = r - 1;
		int p = median3(a, l, r);

		while (1) {
			while (a[++i] < p);
			while (a[--j] > p);
			if (i < j) swap(a[i], a[j]);
			else break;
		}
		swap(a[r - 1], a[i]);

		optimize_quicksort(a, l, i - 1);
		optimize_quicksort(a, i + 1, r);
	}
	else {
		insertsort(a, l, r);
	}
}


// 快排 三路分区去重复 方法一
void quicksort_3way_1(int a[], int l, int r) {
	if (l >= r) return;

	int last = l + (r - l) / 2;
	swap(a[last], a[r]);

	last = l;		 //    <        =		 >
	int e = l;		 //  l----last-------e------r
	for (int i = l; i < r; i++) {
		if (a[i] < a[r]) {
			swap(a[last], a[i]);
			if (e != last)
				swap(a[e], a[i]);
			e++; last++;
			 
		} else if(a[i] == a[r]) {
			swap(a[e], a[i]);
			e++;
		}
	}
	swap(a[e], a[r]);
	quicksort_3way_1(a, l, last - 1);
	quicksort_3way_1(a, e + 1, r);
}

void quicksort_3way_2(int a[], int l, int r) {
	if (l >= r) return;
	// l--p---i----j---q--r
	int mid = l + (r - l) / 2;
	int v = a[mid];
	swap(a[mid], a[r]);

	int i = l - 1, j = r;
	int p = l - 1, q = r;
	while(1) {
		while (a[++i] < v);
		while (a[--j] > v) { if (j == l) break; }
		if (i >= j) break;
		swap(a[i], a[j]);
		//把相等的放两边
		if (a[i] == v)
			swap(a[++p], a[i]);
		if(a[j] == v)
			swap(a[j], a[--q]);
	}
	swap(a[i], a[r]);
	
	//把相等的放中间
	j = i - 1;
	for (int k = l; k < p; k++, j--)
		swap(a[k], a[j]);
	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
		swap(a[i], a[k]);

	quicksort_3way_2(a, l, j);
	quicksort_3way_2(a, i, r);
	
}


int b[100];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	/* quicksort_3way_2(b, 0, n - 1); */
	quicksort_r(b, 0, n - 1);
	/* optimize_quicksort(b, 0, n - 1); */

	for (int i = 0; i < n; i++) cout << b[i] << ' ';
	return 0;
}

