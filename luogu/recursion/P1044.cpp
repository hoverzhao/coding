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
//教学视频
/* https://www.bilibili.com/video/BV1nE411A7ST?from=search&seid=8939224752595272495&spm_id_from=333.337.0.0 */

/* 卡特兰数的公式：h(0)=1,h(1)=1,h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)*h(0) (n>=2)即 */
/* h(n)=h(n-1)*(4*n-2)/(n+1)即h(n)=C(2n,n)/(n+1); */
/* 卡特兰数可以运用的地方有： */
/* 1.括号化 */
/* 矩阵连乘： P=a1×a2×a3×……×an，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积， */
/* 试问有几种括号化的方案； */
/* 2.出栈次序 */
/* 一个栈(无穷大)的进栈序列为1，2，3，…，n，有多少个不同的出栈序列； */
/* 3.凸多边形三角划分 */
/*   在一个凸多边形中，通过若干条互不相交的对角线，把这个多边形划分成了若干个三角形。任务是 */
/* 键盘上输入凸多边形的边数n，求不同划分的方案数f（n）？ */
/*   一位大城市的律师在她住所以北n个街区和以东n个街区处工作。每天她走2n个街区去上班。如果她 */
/* 从不穿越（但可以碰到）从家到办公室的对角线，那么有多少条可能的道路？ */
/*   在圆上选择2n个点,将这些点成对连接起来使得所得到的n条线段不相交的方法数； */
/* 4.给定节点组成二叉搜索树 */
/* 给定N个节点，能构成多少种不同的二叉搜索树； */
/* 5.n对括号正确匹配数目 */
/* 给定n对括号，求括号正确配对的字符串数。 */

// c[i][j] i: put in stack	--j:get out stack
 
// c[i][0] == 1;
// c[0][j] == 0;

// j = i
// c[i][j] = c[i][j - 1];

// j < i;
// c[i][j] = c[i - 1][j] + c[i][j - 1];
long long c[20][20];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) c[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == i)
				c[i][j] = c[i][j - 1];
			else
				c[i][j] = c[i][j - 1] + c[i - 1][j];
		}
	}
	cout << c[n][n];
	return 0;
}

//卡特兰数公式  直接使用会爆掉
/* h(n)=C(2n,n)/(n+1) */

/* #include<bits/stdc++.h> */
/* using namespace std; */
/* long long c(long long n){ */
/* 	long long ans=1; */
/* 	for(long long i=1;i<=n;i++){ */
/* 		ans*=i+n;ans/=i; */
/* 	} */
/* 	return ans/(n+1); */
/* } */
/* int main(){ */
/* 	long long n; */
/* 	scanf("%lld",&n); */
/* 	printf("%lld\n",c(n)); */
/* 	return 0; */
/* } */
