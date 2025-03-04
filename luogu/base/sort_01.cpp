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

void xprintf(int a[], int l, int r) {
	for (int i = l; i <= r; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

int a[500001];

//冒泡排序
void bubblesort(int a[], int l, int r) {
	for (int i = r; i >= l; i--) {
		for (int j = l; j < i; j++) {
			if (a[j] > a[j + 1]) { 
				swap(a[j], a[j + 1]);
			}
		}
	}
}

//冒泡排序优化
void bubblesort_optimize(int a[], int l, int r) {
	bool done = false;
	int last = r;
	do {
		done = true;
		r = last;
		for (int i = l; i < r; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				done = false;
				last = i + 1;
			}
		}
	} while (!done);
}


//插入排序
void insertsort(int a[], int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		for (int j = i; j > l; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
			}
		}
	}
}

//插入排序优化 之减少交换次数
void insertsort2(int a[], int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		int t = a[i]; int j;
		for (j = i; j > l && t < a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = t;
	}
}

// x-------t---y
//插入排序优化 之二分比较
void insertsort3(int a[], int l, int r) {
	for (int i = l; i <= r; i++) {
		int t = a[i];
		int x = l, y = i;
		//找到右边界插入才不会破坏排序的稳定性
		while (x < y) {
			int mid = (x + y) >> 1;
			if (t < a[mid]) y = mid;
			else x = mid + 1;
		}
		// x就是插入点
		for (int j = i; j > x; j--)
			a[j] = a[j - 1];
		a[x] = t;
	}
}

/* //插入排序优化 之稳定排序 */
/* void insertsort4(int a[], int l, int r) { */
/* 	for (int i = l; i <= r; i++) { */
/* 		int t = a[i]; */
/* 		int x = l, y = i; */
/* 		//找到右边界插入才不会破坏排序的稳定性 */
/* 		while (x < y) { */
/* 			int mid = (x + y) >> 1; */
/* 			if (a[mid] == t) x = mid + 1; */		
/* 			else if (t > a[mid]) x = mid + 1; */    //x-------mid---t-----y
/* 			else if (t < a[mid]) y = mid; */		//x---t---mid---------y
/* 		} */
/* 		// x就是插入点 */
/* 		for (int j = i; j > x; j--) */
/* 			a[j] = a[j - 1]; */
/* 		a[x] = t; */
/* 	} */
/* } */

//希尔排序
void shellsort(int a[], int l, int r) {
	int n = r - l + 1;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			for (int j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) {
				swap(a[j], a[j + gap]);
			}
		}
	}
}

// 堆排序
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


int t[500001];

//计数排序 桶排序
void countingsort(int a[], int l, int r) {
	auto [xi, xa] = minmax_element(a, a + r);
	int xmax = *xa, xmin = *xi;
	int len = xmax - xmin + 1;
	int *buckets = new int[len] {};
	for (int i = 0; i < len; i++) {
		buckets[a[i] - xmin]++;
	}
	for (int i = 0, j = l; i < len; i++) {
		while (buckets[i] > 0) {
			a[j++] = i + xmin;
			--buckets[i];
		}
	}
	delete [] buckets;
}

//归并排序
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

	// stl 库优化快拍 可以ac
	/* sort(a, a + n); */

	//普通快排无法AC，输入是有序数 O(n^2)
	/* quicksort2(a, 0, n - 1); */

	/* bubblesort2(a, 0, n - 1); */

	/* insertsort2(a, 0, n - 1); */
	/* insertsort3(a, 0, n - 1); */

	/* heapcreate(a, n); */
	/* heapsort(a, n); */
	// 使用stl priority_queque
	/* for (int i = 0; i < n; i++) { cout << a.top() << ' '; a.pop();} */

	// 计数排序、桶排序
	/* countingsort(a, 0, n - 1); */
	
	// merge排序方案
	/* merge(a, 0, n - 1); */

	radixsort(a, n);

	for (int i = 0; i < n; i++) cout << a[i] << ' ';

	return 0;
}

