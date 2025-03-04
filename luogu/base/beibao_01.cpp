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
	/* freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout); */
#endif
	return 0;
}();

/* #define LINF 0x3f3f3f3f3f3f3f3f */
#define INF  0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef long double ld;

const int NN = 1000;
// volumn 体积  cost 价值	mass 质量  s数量	queue队列  type背包类型
vector<int> v(NN), c(NN), s(NN), dp(NN), z(NN), q(NN), t(NN);
/* int w[NN], c[NN], s[NN], dp[NN], z[NN], q[NN]; */
void xprintf(vector<int> &a, int len) {
	for (auto v : a) {
		if (len--)
			cout << v << ' ';
		else
			break;
	}
	cout << '\n';
}
int main() {
	/* int N, V; */
	/* cin >> N >> V  */

	//经典01背包 (分背包不要求装满和刚好装满 两种情况)
	/* for (int i = 1; i <= N; i++)  cin >> v[i] >> c[i]; //dp[i] = -INF;} */ 
	/* for (int i = 1; i <= N; i++) */
	/* 	for (int j = V; j >= v[i]; j--) */
	/* 		dp[j] = max(dp[j], dp[j - v[i]] + c[i]); */
	/* cout << dp[V]; */

	//点菜 : n种菜，每种菜只能点一次，菜价v[i], 一共消费m元，一共有多少种点菜方法?
	/* dp[0] = 1; */
	/* for (int i = 1; i <= N; i++) cin >> v[i]; */
	/* for (int i = 1; i <= N; i++) { */
	/* 	for (int j = V; j >= v[i]; j--) */ 
	/* 		dp[j] += dp[j - v[i]]; */
	/* } */
	/* cout << dp[V]; */

	//完全背包
	/* for (int i = 1; i <= N; i++) */
	/* 	for (int j = v[i]; j <= V; j++) */
	/* 		dp[j] = max(dp[j], dp[j - v[i]] + c[i]); */
	/* cout << dp[V]; */

	//单调队列 n个数，窗口长度m, 找所有滑动窗口的最大值
	//O(n)
	/* 8 3 */
	/* 2 6 4 9 8 5 5 2 */
	/* ans: 6 9 9 9 8 5 */
	/* int n, m; */
	/* cin >> n >> m; */
	/* int h = 0, t = -1; */
	/* for (int i = 1; i <= n; i++) { */
	/* 	if (h <= t && q[h] < i - m + 1) h++; */
	/* 	while (h <= t && a[i] >= a[q[t]]) t--; */
	/* 	q[++t] = i; */
	/* 	if (i > m - 1) cout << a[q[h]]; */
	/* } */

	//n个数，长度不超过m的连续子序列最大和
	//O(n)
	/* 7 3 */
	/* 2 -3 5 2 -4 -1 8 */
	/* ans: 8 */
	/* int n, m; */
	/* cin >> n >> m; */
	/* int h = 0, t = -1, ans = 0; */
	/* for (int i = 1; i <= n;i++) { int x; cin >> x; s[i] = s[i - 1] + x;} */
	/* q[0] = 0, ans = s[1]; */
	/* for (int i = 1; i <= n; i++) { */
	/* 	if (h <= t && q[h] < i - m) h++; */
	/* 	ans = max(ans, s[i] - s[q[h]]); */
	/* 	while (h <= t && s[i] <= s[q[t]]) t--; */
	/* 	q[++t] = i; */
	/* } */
	/* cout << ans; */

	//多重背包 //单调队列
	//O(VN)
	/* 2 9 */
	/* 3 5 2 */
	/* 2 4 3 */
	/* ans: 17 */
	/* for (int i = 1; i <= N; i++) cin >> v[i] >> c[i] >> s[i]; */
	/* for (int i = 1; i <= N; i++) { */
	/* 	/1* memcpy(z, dp, sizeof(dp)); *1/ */
	/* 	copy(dp.begin(), dp.end(), z.begin()); */
	/* 	//按当前物体体积 v[i] 的余数，把dp[0...V] 拆分为0 ~ v[i] - 1 个类别 */
	/* 	for (int j = 0; j < v[i]; j++) { */ 
	/* 		int h = 0, t = -1; */
	/* 		for (int k = j; k <= V; k += v[i]) { */
	/* 			if (h <= t && q[h] < k - s[i] * v[i]) h++; */
	/* 			//z[q[h]]: q[h]容量的背包，装的最大价值 */
	/* 			if (h <= t) dp[k] = max(z[k], z[q[h]] + (k - q[h]) / v[i] * c[i]); */
	/* 			//q[]队列，按(状态转移公式)值，从大到小排列 */
	/* 			while (h <= t && z[k] >= z[q[t]] + (k - q[t]) / v[i] * c[i]) t--; */

	/* 			q[++t] = k; */
	/* 		} */
	/* 	} */
	/* } */
	/* cout << dp[V]; */
	
	//多重背包 //二进制优化 将第s[i] 件物品，按二进制组合 拆解为 log s[i]件不同物品 
	//O(VΣlogs[i])
	/* 3 7 */
	/* 2 3 12 */
	/* 3 5 15 */
	/* 1 2 3 */
	/* ans:12 */
	/* int N, V;  cin >> N >> V; */
	/* int cnt = 1; */ 	
	/* for (int i = 1; i <= N; i++) { */
	/* 	int vv, cc, ss; */
	/* 	cin >> vv >> cc >> ss; */
	/* 	for (int j = 1; j <= ss; j <<= 1) { */
	/* 		v[cnt] = j * vv; */
	/* 		c[cnt++] = j * cc; */
	/* 		ss -= j; */
	/* 	} */
	/* 	if (ss) { */
	/* 		v[cnt] = ss * vv; */
	/* 		c[cnt++] = ss * cc; */
	/* 	} */
	/* } */
	/* for (int i = 1; i <= cnt; i++) */ 
	/* 	for (int j = V; j >= v[i]; j--) */
	/* 		dp[j] = max(dp[j], dp[j - v[i]] + c[i]); */

	/* cout << dp[V]; */
	
	
	//混合背包： 01 完全 多重 混合
	//			 -1  0    >1
	/* 4 5 */
	/* 1 2 -1 */
	/* 2 4 1 */
	/* 3 4 0 */
	/* 4 5 2 */
	/* ans: 8 */

	/* int N, V; */
	/* cin >> N >> V; */
	/* int vv, cc, ss, cnt; */
	/* //方法1.消去多重--> 01 */ 
	/* cnt = 1; */
	/* for (int i = 1; i <= N; i++) { */
	/* 	cin >> vv >> cc >> ss; */
	/* 	if (ss == 0) { */
	/* 		v[cnt] = vv; c[cnt] = cc; s[cnt++] = 0; */
	/* 	} else { */
	/* 		if (ss == -1) ss = 1; */
	/* 		for (int j = 1; j <= ss; j <<= 1) { */
	/* 			v[cnt] = j * vv; c[cnt] = j * cc; s[cnt++] = 1; ss -= j; */
	/* 		} */
	/* 		if (ss) { */
	/* 			v[cnt] = ss * vv; c[cnt] = ss * cc; s[cnt++] = 1; */
	/* 		} */
	/* 	} */
	/* } */
	/* //易错 要用 i<cnt */ 
	/* for (int i = 1; i < cnt; i++) { */
	/* 	if (s[i] == 1) { */
	/* 		for (int j = V; j >= v[i]; j--) */ 
	/* 			dp[j] = max(dp[j], dp[j - v[i]] + c[i]); */
	/* 	} else { */
	/* 		for (int j = v[i]; j <= V; j++) */
	/* 			dp[j] = max(dp[j], dp[j - v[i]] + c[i]); */
	/* 	} */
	/* } */
	/* cout << dp[V] << endl; */
	
	//方法2. 分类 zero_one_pack	complete_pack multiple_pack (int v, int c)
	/* for (int i = 1; i <= N; i++) { */
	/* 	cin >> vv >> cc >> type; */
	/* 	if (type == -1) zero_one_pack(vv, cc); */
	/* 	else if (type == 0) complete_pack(vv, cc); */
	/* 	else multiple_pack(vv, cc); */
	/* } */


	//二维费用背包: N件物品 背包容量V 总量M， 每件物品v[i], m[i], c[i], 求不超过V、M的情况下，背包装入的最大价值
	//O(VNM)
	/* 4 5 6 */
	/* 1 2 3 */
	/* 2 4 4 */
	/* 3 4 5 */
	/* 4 5 6 */
	/* ans: 8 */
	
	/* int N, V, M; */
	/* cin >> N >> V >> M; */
	/* for (int i = 1; i <= N; i++) cin >> v[i] >> m[i] >> c[i]; */
	/* for (int i = 1; i <= N; i++) */
	/* 	for (int j = V; j >= v[i]; j--) */
	/* 		for (int k = M; k >= m[i]; k--) */
	/* 			dp[j][k] = max(dp[j][k], f[j - v[i]][k - m[i]] + c[i]); */

	/* cout << dp[V][M]; */

	//分组背包 G组物品组, 每组N个物品，容量V背包 ，每组选一个物品，求不超过背包体积的最大价值
	//O(VΣNi)
	//v[i][j] c[i][j]  第i组的第j个物品的体积 价值
	//max(f[i - 1][j], f[i - 1][j - v1] + c1, ... f[i - 1][j - vn] + wn)
	/* 2 6 */
	/* 2 */
	/* 1 2 */
	/* 2 3 */
	/* 3 */
	/* 1 1 */
	/* 3 5 */
	/* 2 4 */
	/* ans: 8 */
	/* int G, N, V; */ 
	/* cin >> G >> V; */
	/* for (int i = 1; i <= G; i++) { */
	/* 	cin >> N; */
	/* 	for (int j = 1; j <= N; j++) */ 
	/* 		cin >> v[j] >> c[j]; */

	/* 	for (int j = V; j >= 1; j--) { */
	/* 		for (int k = 0; k <= N; k++) { */
	/* 			if (j >= v[k]) */
	/* 				dp[j] = max(dp[j], dp[j - v[k]] + c[k]); */
	/* 		} */
	/* 	} */
	/* } */
	/* cout << dp[V]; */
	return 0;
}

