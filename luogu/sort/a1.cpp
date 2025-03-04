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

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;


int a[500001];

int read() {
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') 
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}


void qksort(int *a, int l, int r) {
	if (l >= r) return;
	int i = l - 1, j = r;
	int p = a[r];

	/* while (i < j) { */
	/* 	while (a[++i] < p); */
	/* 	while (a[--j] > p); */
	/* 	if (i < j) */
	/* 		swap(a[i], a[j]); */
	/* } */

	while (1) {
		while (a[++i] < p);
		while (a[--j] > p);
		if (i < j)
			swap(a[i], a[j]);
		else
			break;
	}
	swap(a[r], a[i]);
	qksort(a, l, i - 1);
	qksort(a, i + 1, r);
}

void qksort2(int *a, int l, int r) {
	if (l >= r) return;
	
	int last = l + (r - l) / 2;
	swap(a[last], a[l]);
	last = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < a[l])
			swap(a[++last], a[i]);
	}
	swap(a[last], a[l]);
	qksort2(a, l, last - 1);
	qksort2(a, last + 1, r);
}



int t[500001];
void merge(int a[], int l, int r) {
	if (l >= r) return ;
	int mid = (r + l) >> 1;
	merge(a, l, mid);
	merge(a, mid + 1, r);
	int i = l, j = mid + 1, pos = 0;
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) t[pos++] = a[i++];
		else t[pos++] = a[j++];
	}
	while (i <= mid) t[pos++] = a[i++];
	while (j <= r) t[pos++] = a[j++];
	for (i = l, j = 0; i <= r; i++, j++) a[i] = t[j];
}


int main() {
	int n;
	cin >> n;
	/* map<int, int> a; */ 
	/* int k = 0; */
	//优先队列
	/* std::priority_queue<int, vector<int>, std::greater<int> > a; */
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		/* cin >> k; */
		/* a.push(k); */

		/* a[k]++; */
	}

	// 打乱输入顺序 ，但无法处理，连续相同数字情况
	/* random_device rd; */
	/* mt19937 rnd(rd()); */
	/* shuffle(a, a+ n, rnd); */

	// 快读无效,会更慢(空格过多)
	/* for (int i = 0; i < n; i++) a[i] = read(); */

	/* for (int i = 0; i < n; i++) cout << a[i] << ' '; */

	// stl 库优化快拍 可以ac
	/* sort(a, a + n); */

	//普通快排无法AC，输入是有序数 O(n^2)
	/* qksort2(a, 0, n - 1); */

	//merge排序方案
	merge(a, 0, n - 1);

	// map 桶排序
	/* for (auto it = a.begin(); it != a.end(); it++) { */
	/* 	int k = it->second; */
	/* 	while (k--) cout << it->first << ' '; */
	/* } */

	for (int i = 0; i < n; i++) cout << a[i] << ' ';

	return 0;
}

