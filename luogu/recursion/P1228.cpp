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

static int z = []() {
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
/* 由此可想到将一个边长为2^k的正方形分成四个边长为2^{k - 1} 的正方形公主必在其中的一个正方形中， */
/* 然后再中心摆上一个地毯，地毯缺少的一块朝向公主所在正方形，这样相当于每个小正方形中有一个公主。 */

ll x,y,len; int k;
ll fun(int k)
{
    ll sum=1;
    for(int i=1;i<=k;++i) sum*=2;
    return sum;
}

//x y 占用的格子, l长度（宽度）, a b 左上角坐标
void solve(ll x, ll y, ll a, ll b, ll l)
{
    if(l==1) return;
	//左上区域
    if(x - a <= l / 2 - 1 && y - b <= l / 2 - 1)
    {
        /* printf("%lld %lld 1\n", a + l / 2, b + l / 2); */
		cout << a + l / 2 << ' ' << b + l / 2 << ' ' << 1 << '\n';
        solve(x, y, a, b, l / 2);
        solve( a + l / 2 - 1, b + l / 2, a,  b + l / 2, l / 2);		//右上
        solve( a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);		//左下
        solve( a + l / 2, b + l / 2, a + l / 2, b + l / 2,l / 2);	// 右下 
    } //  右上区域
    else if(x - a <= l / 2 - 1 && y - b > l / 2 - 1)
    {
        /* printf("%lld %lld 2\n", a + l / 2, b + l  / 2 - 1); */
		cout << a + l / 2 << ' ' << b + l / 2  - 1 << ' ' << 2 << '\n';
        solve( a + l  / 2 - 1, b + l  / 2 - 1,a, b, l / 2);
        solve(x, y, a,  b + l / 2,l / 2);
        solve( a + l / 2, b + l / 2 - 1, a + l / 2,b, l / 2);
        solve( a + l / 2, b + l / 2, a + l / 2, b + l / 2,l / 2);
    }
    else if(x-a>l / 2 - 1 && y-b<=l / 2 - 1)
    {
        /* printf("%lld %lld 3\n", a + l / 2 - 1, b + l / 2); */
		cout << a + l / 2 - 1 << ' ' << b + l / 2 << ' ' << 3 << '\n';
        solve( a + l  / 2 - 1, b + l / 2 - 1, a, b, l / 2);
        solve( a + l  / 2 - 1, b + l / 2, a,  b + l / 2,l / 2);
        solve(x, y,  a + l / 2,b, l / 2);
        solve( a + l / 2, b + l / 2, a + l / 2, b + l / 2,l / 2);
    }
    else
    {
        /* printf("%lld %lld 4\n", a + l / 2 - 1, b + l / 2 - 1); */
		cout << a + l / 2 - 1 << ' ' << b + l / 2 - 1 << ' ' << 4 << '\n';
        solve( a + l  / 2 - 1, b + l / 2 - 1,a, b, l / 2);
        solve( a + l  / 2 - 1, b + l / 2,a,  b + l / 2,l / 2);
        solve( a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
        solve(x, y,  a + l / 2, b + l / 2,l / 2);
    }
}

int main()
{
	cin >> k >> x >> y;
    len=fun(k);
    solve(x, y, 1,1,len);
    return 0;
}
