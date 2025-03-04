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

/* int dp[35][205]; */
int dp[205];
int w[35];
int c[35];


int main() {
	int n, m;
	cin >> m >> n;
/* 	for (int i = 1; i <= n; i++) { */
/* 		cin >> w[i] >> c[i]; */
/* 	} */

/* //01背包 */ 

/* 	//	初始化 (不要求装满） */
/* 	for (int i = 0; i <= n; i++) dp[i] = 0; */
/* 		/1* for( int j = 0; j <= m; j++) dp[i][j] = 0; *1/ */

/* 	//	初始化 (恰好装满） */
/* 	for (int i = 1; i <= n; i++) dp[i] = -INF; dp[0] = 0; */ 

/* 	//	朴素解法 */
/* 	for (int i = 1; i <= n; i++) */
/* 		for (int j = 1; j <= m; j++) */
/* 			if (j < w[i])	dp[i][j] = dp[i - 1][j]; */
/* 			else			dp[i][j] = max(dp[i - 1][j - w[i]] + c[i], dp[i - 1][j]); */

/* 	//	优化解法 */
/* 	for (int i = 1; i <= n; i++) */  
/* 		for (int j = m; j >= w[i]; j--) */  
/* 			dp[j] = max(dp[j], dp[j - w[i]] + c[i]); */ 

/* //	点菜求方案数 要求钱刚好花完*/
	//	n道菜，每道菜价格a[i], 有m元，问全花光有多少种点菜方案?
	//	dp[j] 有j元时，可以有多少种点菜方案?
/*	dp[0] = 1; */
/*	for (int i = 1; i <= n; i++) */ 
/*		for (int j = m; j >= a[i]; j--) */ 
/*			dp[j] = dp[j] + dp[j - a[i]]; */
		

/* //完全背包 */ 

/* 	//	初始化 (不要求装满） */
/* 	/1* for (int i = 0; i <= n; i++) dp[i] = 0; *1/ */
/* 	//	初始化 (恰好装满） */
/* 	for (int i = 1; i <= n; i++) dp[i] = -INF; dp[0] = 0; */ 

/* 	//	朴素解法 */
/* 	for (int i = 1; i <= n; i++) */
/* 		for (int j = m; j >= 1; j--) */
/* 			for (int k = 0; k <= j / w[i]; k++) */
/* 					dp[j] = max(dp[j], dp[j - k * w[i]] + k * c[i]); */

/* 	//	优化解法 */
/* 	/1* for (int i = 1; i <= n; i++) *1/ */ 
/* 	/1* 	for (int j = w[i]; j <= m; j++) *1/ */ 
/* 	/1* 		dp[j] = max(dp[j - w[i]] + c[i], dp[j]); *1/ */
	
/* //多重背包 */
	//朴素算法
	//输入数据 
	//9 2 
	//3 5 2
	//2 4 3
	int v,p,s;
	for (int i = 1; i <= n; i++) {
/*		//n个物品，第i个物品体积v、价值为p、 数量为s */
		cin >> v >> p >> s;
		for (int j = m; j >= v; j--) {
			for (int k = 1; k <= s && j >= k * v; k++) {
				dp[j] = max(dp[j], dp[j - k * v] + k * p);
				printf("dp[%d] = %2d  dp[%d] + %d = %d \n", 
						j, dp[j], j - k * v, k * p, dp[j - k * v] + k * p);
			}
		}
	}

/* 	//二进制优化 */
/*		//n个物品，第i个物品有c个、重量为w、 价值为p */
/*		//原理 将c进行2进制拆分，比如 c=10， 拆分1， 2， 4， 3，四个物品、 则这四个数组合 可以是10内的任何数， */ 
/*		//     因此 转换为0、1背包问题		利用动态规划，解决组合最优问题 */ 
/* 	for (int i = 0; i < N; i++) { */
/* 		cin >> w >> p >> c; */
/* 		for (int k = 1; k <= c; k <<= 1) { */
/* 			val[cnt] = k * p; */
/* 			sz[cnt++] = k * w; */
/* 			c -= k; */
/* 		} */
/* 		if (c > 0) val[cnt] = c * p, sz[cnt++] = c * w; */
/* 	} */
/* 	for (int i = 0; i < cnt; i++) { */
/* 		for (int j = W; j >= sz[i]; j--) { */
/* 			dp[j] = max(dp[j], dp[j - sz[i]] + val[i]); */
/* 		} */
/* 	} */
/* 	//输出 */
/* 	/1* cout << dp[n][m]; *1/ */
	cout << dp[m];
	return 0;
}

/* int q[20002]; */
/* int f[20002],g[20002]; */
/* int n, m; */

/* int main() { */
/* 	int v,w,s; */
/* 	cin >> n >> m; */
/* //多重背包 */ 
/* 	//单调队列优化  */
	for(int i = 1;i <= n; i++){
		memcpy(g, f, sizeof(f)); //f备份到g   
		cin >> v >> w >> s; //体积 价值 数量
		for(int j = 0;j < v; j++){ //分拆成v个类 
			int h = 0,t = -1;
			for(int k = j;k <= m;k += v){ //对每个类使用单调队列 
				//q[h]不在窗口[k-s*v,k-v]内,队头出队
				if(h <= t && q[h] < k - s * v) h++;
				//使用队头最大值更新f 
				if(h <= t) f[k] = max(g[k], g[q[h]] + (k - q[h]) / v * w);
				//当前值比队尾值更有价值,队尾出队. 下面行等价
				while(h <= t && g[k] - (k - j) / v * w >= g[q[t]] - (q[t] - j) / v * w) t--;
				while(h <= t && g[k] >= g[q[t]] + (k - q[t]) / v * w) t--;
				//下标入队,便于队头出队
				q[++t] = k;
			}
		}
	}
	printf("%d\n",f[m]);
/* } */

