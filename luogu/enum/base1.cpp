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

//基础排列算法
void permute(string a, int l, int r) {
	if (l == r) {
		cout << a << '\n';
		return;
	}
	for (int i = l; i <= r; i++) {
		swap(a[l], a[i]);
		permute(a, l + 1, r);
		swap(a[l], a[i]);
	}
}

// n个数中取m个的全排列
void permute_part(int a[], int l, int r, int deep) {
	if (deep == 0) {
		xprintf(a, 3);
		return;
	}
	for (int i = l; i <= r; i++) {
		swap(a[l], a[i]);
		permute_part(a, l + 1, r, deep - 1);
		swap(a[l], a[i]);
	}
}

//下一个字典序排列数
/* 1.从右到左扫描,发现第一个违背递增趋势的数字,称之为 PartitionNumber. */
/* 2.从右到左进行扫描,发现第一个比 PartitionNumber 要大的数,称之为 ChangeNumber. */
/* 3.交换 PartitionNumber 和 ChangeNumber.这样一步,会使得新的排列组成的数比旧的排列组成的数要大,当然,新数增长的幅度不一定是最小的. */
/* 4.反转在 PartitionNumber 右侧的数.此时, PartitionNumber 右侧的排列已经是严格的从大到小排列了, */
/*   如此反转之后,可以保证,新的排列组成的数的增长幅度在所有的可能中最小. */
int my_next_permutation(int num[], int first, int last) {
    int i, j;
    i = last - 2; /* PartitionNumber's index */
    while (i >= 0 && num[i] >= num[i + 1]) i--;

    if (i == -1) {
        reverse(num + first, num + last);
        return 0;
    }

    j = last - 1;
    while (num[j] <= num[i]) --j;
    swap(num[i], num[j]);
    reverse(num + i + 1, num + last);
    return 1;
}
//全排列stl解法

int a[100];
int main() {
	/* int n, r; */
	/* cin >> n >> r; */
	/* back_combination(n, r, r); */
	/* front_combination(n, r, 1, r); */
	int n;
	/* string a = "12345"; */
	cin >> n;
	/* permute(a, 0, n - 1); */
	/* permutation(n, 1); */

	/* vector<int> a(n, 0); */
	for (int i = 0; i < n; i++) { a[i] = i + 1; }
	/* do { */
	/* 	for (int i = 0; i < n; i++) { cout << setw(5) << a[i]; } */
	/* 	cout << '\n'; */
	/* } while (next_permutation(a.begin(), a.end())); */
	permute_part(a, 0, n - 1, 3);
	return 0;
}
