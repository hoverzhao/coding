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
/* 1.从右到左扫描,发现第一个违背递增趋势的数字,称之为 PartitionNumber. */
/* 2.从右到左进行扫描,发现第一个比 PartitionNumber 要大的数,称之为 ChangeNumber. */
/* 3.交换 PartitionNumber 和 ChangeNumber.这样一步,会使得新的排列组成的数比旧的排列组成的数要大,当然,新数增长的幅度不一定是最小的. */
/* 4.反转在 PartitionNumber 右侧的数.此时, PartitionNumber 右侧的排列已经是严格的从大到小排列了, */
/*   如此反转之后,可以保证,新的排列组成的数的增长幅度在所有的可能中最小. */

void xprintf(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

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

int c[10001];
int main() {
	int n, m;
	cin >> n >> m;
	/* vector<int> a(n); */
	for (int i = 0; i < n; i++) cin >> c[i];
	/* for (int i = 0; i < n; i++) cin >> a[i]; */
	int k = 0;
	do {
		if (++k > m) break;
	/* } while (next_permutation(a.begin(), a.end())); */
	} while (my_next_permutation(c, 0, n));
	for (int i = 0; i < n; i++) cout << c[i] << ' ';
	return 0;
}

