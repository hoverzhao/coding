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

const int N = 1000;
const int mod = 1e9 + 7;
vector<int> c(N), f(N), v(N), w(N), s(N);
int main() {

	//点菜 : n种菜，每种菜只能点一次，菜价v[i], 一共消费m元，一共有多少种点菜方法?
	// n个物品，容量为m，刚好装满，不考虑最大价值，一共有多少种方案
	/* 4 4 */
	/* 1 1 2 2 */
	/* ans: 3 */
	/* s[0] = 1; */
	/* for (int i = 1; i <= N; i++) cin >> v[i]; */
	/* for (int i = 1; i <= N; i++) { */
	/* 	for (int j = V; j >= v[i]; j--) */ 
	/* 		s[j] += s[j - v[i]]; */
	/* } */
	/* cout << s[V]; */

	//01背包 求最大价值选法的 方案数 
	/* 5 5 */
	/* 5 8 */
	/* 2 4 */
	/* 3 4 */
	/* 5 7 */
	/* 4 8 */
	/* int n, m; */
	/* cin >> n >> m; */
	/* for (int i = 1; i <= n; i++) cin >> v[i] >> c[i]; */

	/* //背包不装入物品，也是一种方案(未装满) */
	/* for (int i = 0; i <= m; i++) s[i] = 1; */

	/* //要求(装满)的情况 1~n f[i]=-INF s[i]=0;  f[0]=0 s[0]=1 */
	/* /1* for (int i = 0; i <= m; i++) f[i] = -INF; *1/ */
	/* /1* f[0] = 0; s[0] = 1; *1/ */

	/* for (int i = 1; i <= n; i++) { */
	/* 	for (int j = m; j >= v[i]; j--) { */
	/* 		//总方案数并未增加 */
	/* 		if (f[j - v[i]] + c[i] > f[j]) { */
	/* 			f[j] = f[j - v[i]] + c[i]; */
	/* 			s[j] = s[j - v[i]]; */
	/* 		} */ 
	/* 		else if (f[j - v[i]] + c[i] == f[j]) { */
	/* 			s[j] = (s[j] + s[j - v[i]]) % mod; */
	/* 		} */
	/* 	} */
	/* } */
	/* cout << s[m]; */

	//01背包，求出具体方案（按字典序输出）
	//
	//要求字典序最小，如果存在包含第一个物品的最优解，那么必然要选择第一个，
	//问题转换为从2~n中找到最优解！
	//1、从后往前遍历物品，让最优解落在f[1][m]中，
	//2、从f[1][m]开始搜索字典序最小的路径方案。
	//f[i][j]  从第i个物品，到最后一个物品，装入容量为j的背包的最优解
	//状态转移 f[i][j] = max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]);
	//
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i] >> c[i];

	//从后向前推导，所以初始化 n+1 元素 = 0，
	for (int j = 0; j <= m; j++) f[n + 1][j] = 0;

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= m; j++) {
			f[i][j] = f[i + 1][j];
			if (j >= v[i])
				f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + c[i]);
		}
	}
	//f[1][m]就是最大价值
	int j = m;
	for (int i = 1; i <= n; i++) {
		if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + c[i]) {
			cout << i << ' ';
			j -= v[i];
		}
	}
	//完全背包，求具体方案（按字典序输出）
	//将上面的 f[i + 1]*** 修改为f[i] 即可；
	return 0;
}

