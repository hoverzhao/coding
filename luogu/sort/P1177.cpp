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

void xprintf(int a[], int l, int r) {
	for (int i = l; i <= r; i++)
		cout << a[i] << ' ';
	cout << '\n';
}


void qksort(int *a, int l, int r) {
	if (l >= r) return;
	int i = l - 1, j = r;
	int p = a[r];
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


/* int q[500001]; */
/* void merge(int * a, int l, int r) { */
/* 	if ( l >= r ) return; */
/* 	int mid = l + r >> 1; */
/* 	merge(a, l, mid); */
/* 	merge(a, mid + 1, r); */
/* 	int pos = 0, i = l, j = mid + 1; */
/* 	while (i <= mid && j <= r) { */
/* 		if (a[i] < a[j]) q[pos++] = a[i++]; */
/* 		else q[pos++] = a[j++]; */
/* 	} */
/* 	while (j <= r) q[pos] = a[j++]; */
/* 	while (i <= mid) q[pos] = a[i++]; */
/* 	for (i = 0, j = l; j <= r; i++, j++) a[j] = q[i]; */

/* } */
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

void quicksort_3way(int a[], int l, int r) {
	if (l >= r) return;
	/* xprintf(a, l, r); */
	
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
	quicksort_3way(a, l, last - 1);
	quicksort_3way(a, e + 1, r);
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

/* void quicksort_r(int a[], int l, int r) { */
/* 	if (l >= r) return; */
	
/* 	int last = l + (r - l) / 2; */
/* 	swap(a[last], a[r]); */
/* 	last = l; */
/* 	for (int i = l; i <= r; i++) { */
/* 		if (a[i] < a[r]) */
/* 			swap(a[last++], a[i]); */
/* 	} */
/* 	swap(a[last], a[r]); */
/* 	quicksort_r(a, l, last - 1); */
/* 	quicksort_r(a, last + 1, r); */
/* } */
void shift_down(int a[], int id, int len) {
	while (id * 2 <= len) {
		int l = id * 2;
		int r = id * 2 + 1;
		int t = a[id - 1] > a[l - 1] ? id : l;
		if (r <= len && a[t - 1] < a[r - 1])
			t = r;
		if (t != id ) {
			swap(a[id - 1], a[t - 1]);
			id = t;
		} else break;
	}
}

//注意堆编号从1开始 l= i * 2; r = i * 2 + 1才成立
void heapcreate(int a[], int len) {
	int now = len / 2;
	for (int id = now; id >= 1; id--) {
		shift_down(a, id, len);
	}
}

void heapsort(int a[], int len) {
	while (len > 0) {
		swap(a[0], a[len - 1]);
		len--;
		shift_down(a, 1, len);
	}
}

//基数排序
int maxbit(int a[], int n) {
	int mx = std::numeric_limits<int>::min(); 
	for (int i = 0; i < n; ++i) {
		if (mx < a[i]) 
			mx = a[i];
	}
	int d = 1;
	while (mx /= 10) d++;
	return d;
}

void radixsort(int a[], int n) {
	int d = maxbit(a, n);
	int *tmp = new int[n];
	int *count = new int[10]; //计数器
	int i, j, k; //k 每位的对应的数字 比如235 十位是3，k就为3
	int radix = 1; //每位对应的基数 比如235 十位radix = 10;
	for (i = 1; i <=d; i++) {
		memset(count, 0, sizeof(int) * 10);
		for (j = 0; j < n; j++) {
			k = (a[j] / radix) % 10;
			count[k]++;
		}
		for(j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //count 累加后记录 相同位值的m个数字的 最大索引位置
		for(j = n - 1; j >= 0; j--) {
			k = (a[j] / radix) % 10;
			tmp[count[k] - 1] = a[j];  //位置
			count[k]--;
		}
		for (j = 0; j < n; j++)
			a[j] = tmp[j];
		radix *= 10;
		
	}
	delete [] tmp; 
	delete [] count; 
}

int main() {
	int n;
	cin >> n;
	/* map<int, int> a; */ 
	/* int k = 0; */
	//优先队列
	/* std::priority_queue<int, vector<int>, std::greater<int> > a; */
	/* priority_queue<int> a; */
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		/* cin >> k; */
		/* a.push(k); */

		/* a[k]++; */
	}
	/* heapcreate(a, n); */
	/* xprintf(a, 0, n - 1); */
	/* heapsort(a, n); */

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
	/* merge(a, 0, n - 1); */
	/* quicksort_3way_2(a, 0, n - 1); */
	/* quicksort_r(a, 0, n - 1); */
	// map 桶排序
	/* for (auto it = a.begin(); it != a.end(); it++) { */
	/* 	int k = it->second; */
	/* 	while (k--) cout << it->first << ' '; */
	/* } */

	radixsort(a, n);
	for (int i = 0; i < n; i++) cout << a[i] << ' ';

	return 0;
}

