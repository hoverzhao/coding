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


vector<int> t(1000);

// 求组合，   选择范围的右边界            0 --(n - m)  
// 按字典序输出
void front_combination(vector<int> &a, int l, int r, int m) {
	int n = (int)a.size();
	if ( r < n) {
		for (int i = l; i <= r; i++) {
			t[r] = i;
			front_combination(a, i + 1, r + 1, m);
		}
	} else {
		for (int i = n - m; i < n; i++) { cout << setw(3) << a[t[i]] ; }
		cout <<'\n';
	}
}

// n个不同的数，取其中m个数, 一共多少种取法
/* 1. 选择第i（m <=i<=n）个元素作为每个组合的最后元素，在第1————i个元素中往前（前i - 1个元素中）选取m-1个元素。 */
/* 2. 若m等于1（对应b[0]），则表示选完，输出该组合（数组b中存储的是组合的元素在a中的下标） */
/* 3. 若m>1，则重复1、2步骤 */

// 求组合        选择范围的左边界0 --(m - 1)--(n - 1)  l >= 1  m最小为2
// 按字典序输出
void back_combination(vector<int> &a, int l, int r, int m) {
	for (int i = l; i <= r; i++) {
		t[l] = i;
		if (l > 0) {
			back_combination(a, l - 1, i - 1, m);
		} else {
			for (int j = 0; j < m; j++) { cout << setw(3) << a[t[j]] ; }
			cout << '\n';
		}
	}
}

//求排列 数组a[]元素各不相同 
//字典序 
int book[30];
void permute_order(vector<int> &a, int l, int r) {
	if (l > r) {
		for (int i = 0; i < (int)a.size(); i++) cout << a[t[i]] << ' '; 
		cout << '\n';
		return;
	}
	for (int i = 0; i < (int)a.size(); i++) {
		if(book[i]) continue;
		book[i] = 1;
		t[l] = i;
		permute_order(a, l + 1, r);
		book[i] = 0;
	}
}

//求排列 数组a[]元素各不相同 
//无序 
void permute(vector<int> a, int l, int r) {
	if (l == r) {
		for (auto v : a) cout << v << ' ';
		cout << '\n';
		return;
	}
	for (int i = l; i <= r; i++) {
		swap(a[l], a[i]);
		permute(a, l + 1, r);
		swap(a[l], a[i]);
	}
}

// 求排列 n个数中取m个的排列 
// 无序 (l无效)
void permute_part(vector<int> &a, int l, int r, int m, int step) {
	if (m == step) {
		for (int i = 0; i < m; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = l; i <= r; i++) {
		swap(a[l], a[i]);
		permute_part(a, l + 1, r, m, step + 1);
		swap(a[l], a[i]);
	}
}

//下一个字典序排列数
/* 1.从右到左扫描,发现第一个违背递增趋势的数字,称之为 PartitionNumber. */
/* 2.从右到左进行扫描,发现第一个比 PartitionNumber 要大的数,称之为 ChangeNumber. */
/* 3.交换 PartitionNumber 和 ChangeNumber.这样一步,会使得新的排列组成的数比旧的排列组成的数要大,当然,新数增长的幅度不一定是最小的. */
/* 4.反转在 PartitionNumber 右侧的数.此时, PartitionNumber 右侧的排列已经是严格的从大到小排列了, */
/*   如此反转之后,可以保证,新的排列组成的数的增长幅度在所有的可能中最小. */
int my_next_permutation(int a[], int first, int last) {
    int i, j;
    i = last - 2; /* Partitionaber's index */
    while (i >= 0 && a[i] >= a[i + 1]) i--;

    if (i == -1) {
        reverse(a + first, a + last);
        return 0;
    }

    j = last - 1;
    while (a[j] <= a[i]) --j;
    swap(a[i], a[j]);
    reverse(a + i + 1, a + last);
    return 1;
}

//全排列stl解法
int a[100];
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) { a[i] = i + 1; }

	/* back_combination(a, m - 1, n - 1, m); */
	/* front_combination(a, 0, n - m, m); */
	 
	/* permute(a, 0, n - 1); */
	/* permute_order(a, 0, n - 1); */
	permute_part(a, 0, n - 1, m, 0);

	/* do { */
	/* 	for (int i = 0; i < n; i++) { cout << setw(5) << a[i]; } */
	/* 	cout << '\n'; */
	/* } while (next_permutation(a.begin(), a.end())); */
	return 0;
}
