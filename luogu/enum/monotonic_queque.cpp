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

int n,m;
int s[10001];
int q[10001];
int a[10001];
int main()
{
	int i,x,h,t,ans;

	cin>> n >> m;

// 滑动窗口最大值
	/* for(int i = 1;i <= n;i++) */
	/* 	cin >> a[i]; */
	//方法一
	/* h=0,t=-1; */
	/* for(int i = 1;i <= n;i++){ */
	/* 	//q[h]不在窗口[i-m+1,i]内,队头出队 */
	/* 	if(h <= t && q[h] < i - m + 1) h++; */
	/* 	//当前值>=队尾值,队尾出队  */
	/* 	while(h <= t && a[i] >= a[q[t]]) t--; */
	/* 	//下标入队,便于队头出队 */
	/* 	q[++t] = i; */
	/* 	//使用队头最大值  */
	/* 	if(i > m - 1) printf("%d ",a[q[h]]); */
	/* } */ 

	//方法二
	/* deque<int> q; */
	/* for (int i = 1; i <= n; i++) { */
	/* 	if (!q.empty() && q.front() < i - m + 1) */
	/* 		q.pop_front(); */
	/* 	while (!q.empty() && a[i] >= a[q.back()]) */
	/* 		q.pop_back(); */
	/* 	q.push_back(i); */
	/* 	/1* cout << i << "* "; *1/ */
	/* 	if (i > m - 1) printf("%d ", a[q.front()]); */
	/* } */

// 连续子序列最大和
//	//输入数据
	/* 7 3 */
	/* 3 5 -9 -2 -3 -4 -5 */
	s[0]=0;
	for(i=1;i<=n;i++){
		cin >> x;
		s[i] = s[i-1] + x;
		printf("%2d ", s[i]);
	}
	printf("\n");

	/* h = 0,t = -1;    //无法处理前两个数为正，后面全部为负数的情况 */
	h = 0,t = 0;
	q[0] = 0,ans = s[1];

	for(int i = 1;i <= n;i++){
		if (t >= 0)
			printf(" i = %d q[%d] = %d q[%d] = %d \n", i, h, q[h], t, q[t]);
		//q[h]不在窗口[i - m, i - 1]内，队头出队
		if(h <= t && q[h] < i - m) {h++; printf("		①	h = %d\n", h); }
		//使用队头最小值
		ans = max(ans, s[i] - s[q[h]]);  printf("		②	s[%d] - s[%d] = %d \n", i, q[h], s[i] - s[q[h]]);
		//当前值<= 队尾值，队尾出队
		while(h <= t && s[i] <= s[q[t]]) {printf("		③	t = %d\n", t); t--; }
		//新下标入队
		q[++t] = i;printf("		④	q[%d] = %d \n",t, i);
	}

	printf(" ans=%d\n",ans);
	return 0;

} 

