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
const int N = 100;

vector<int> b(N), w(N), v(N), c(N);
vector<vector<int>> a(N, vector<int>(N));
vector<vector<int>> f(N, vector<int>(N));
int n, m, root;

void dfs(int u) {
	f[u][1] = w[u];
	for (int i = 0; i < b[u]; i++) {
		int son = a[u][i];
		dfs(son);
		f[u][0] += max(f[son][0], f[son][1]);
		f[u][1] += f[son][0];
	}
}

void dfs2(int u) {
	//选u，体积不能小于v[u], f[u][i] 的初值 为c[u];
	printf("进入%d \n", u);

	for (int i = v[u]; i <= m; i++) {f[u][i] = c[u]; printf("f[%d][%d]=%d\n", u, i, f[u][i]); }
	/* for (int i = v[u]; i <= m; i++) {f[u][i] = c[u]; } */
	for (int i = 0; i < b[u]; i++) {
		//儿子节点编号
		int s = a[u][i]; 
		dfs2(s);
		for (int j = m; j >= v[u]; j--) {
			for (int k = 0; k <= j - v[u]; k++) {
				/* printf("f[%d][%d]=%d f[%d][%d]+f[%d][%d]=%d+%d=%d \n", u, j, f[u][j],  u, j - k, s, k, f[u][j - k], f[s][k], f[u][j - k] + f[s][k]); */
				f[u][j] = max(f[u][j], f[u][j - k] + f[s][k]);
			}
		}
		/* printf("返回%d, 由%d更新%d \n", u, s, u); */
	}
}

int main() {
	// 没有上司的舞会, N名职员, 父节点是子节点的直接上司，每个职员有快乐指数w[i]
	// 没有职员愿意和直接上司一起参会，求快乐指数最大总和. 
	// 以u为根节点 ：包括f[u][1]  不包括f[u][0]
	// 1.选u, f[u][1] += Σf[s][0]
	// 2.不选u，f[u][0] += Σmax(f[s][1], fs[s][0])
	/* 7 */
	/* 1 1 1 1 1 1 1 */ 
	/* 2 3 */
	/* 1 3 */
	/* 7 4 */
	/* 6 4 */
	/* 3 5 */
	/* 4 5 */
	/* ans: 5 */
	/* int n; */
	/* cin >> n; */
	/* vector<bool> fa(n, false); */
	/* for (int i = 1; i <= n; i++) cin >> w[i]; */
	/* for (int i = 1; i < n; i++) { */
	/* 	int x, y; */
	/* 	cin >> x >> y; */
	/* 	//y的子节点 值x存入a, 个数存入b */
	/* 	a[y][b[y]++] = x; */
	/* 	// x有父节点 */
	/* 	fa[x] = true; */
	/* } */
	/* //找根节点 */
	/* int root = 1; */
	/* while (fa[root]) root++; */
	/* dfs(root); */
	/* cout << max(f[root][0], f[root][1]); */


	//有依赖的背包
	// N个物品容量V的背包， 物品依赖条件：如果选择一个物品则必须选择
	// 它的父节点，物品编号i, 体积v[i] 价值c[i] 父节点p[i](-1为根节点),
	// 求不超过背包容量的最大价值
	// 解： 设u为节点的子树、容量为j的背包，最大价值 f[u][j]
	//		u的第i个子节点==第s[i]组物品、每组物品 有0， 1， 2， j - v[u] 体积决策 
	//		(按选择体积分组，选择有唯一性，进而转化为分组背包)
	/* 5 6 */
	/* 4 4 3 */
	/* 2 2 3 */
	/* 2 3 -1 */
	/* 1 3 2 */
	/* 1 1 2 */
	/* ans:9 */
	cin >> n >> m ;
	cout << n << ' ' << m << endl;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> v[i] >> c[i] >> p;
		if (p == -1) root = i;
		else a[p][b[p]++] = i;
	}
	dfs2(root);
	cout << f[root][m];
	return 0;
}


