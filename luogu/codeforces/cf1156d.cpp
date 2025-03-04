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
#define int long long//???????????long long???
int n,a[10005];
inline void get(int i)
{
	int aandb,aorb,axorb,aandc,aorc,axorc,bandc,bxorc,x,y,z;//x=a+b,y=a+c,z=b+c,????????
	cout<<"and "<<i-2<<' '<<i-1<<endl;
	cin>>aandb;
	cout<<"or "<<i-2<<' '<<i-1<<endl;
	cin>>aorb;
	axorb=aandb^aorb;
	cout<<"and "<<i-2<<' '<<i<<endl;
	cin>>aandc;
	cout << "xxxxc" << aandc << endl;
	cout<<"or "<<i-2<<' '<<i<<endl;
	cin>>aorc;
	axorc=aandc^aorc;
	bxorc=axorb^axorc;
	cout<<"and "<<i-1<<' '<<i<<endl;
	cin>>bandc;
	x=axorb+2*aandb;
	y=axorc+2*aandc;
	z=bxorc+2*bandc;
	a[i-2]=(x+y+z)/2-z;
	a[i-1]=(x+y+z)/2-y;
	a[i]=(x+y+z)/2-x;
	if(i+1==n)//n%3=1???
	{
		cout<<"and "<<i<<' '<<i+1<<endl;
		cin>>x;
		cout<<"or "<<i<<' '<<i+1<<endl;
		cin>>y;
		a[i+1]=(x^y)+2*x-a[i];
	}
	if(i+2==n)//n%3=2???
	{
		cout<<"and "<<i<<' '<<i+1<<endl;
		cin>>x;
		cout<<"or "<<i<<' '<<i+1<<endl;
		cin>>y;
		a[i+1]=(x^y)+2*x-a[i];
		cout<<"and "<<i<<' '<<i+2<<endl;
		cin>>x;
		cout<<"or "<<i<<' '<<i+2<<endl;
		cin>>y;
		a[i+2]=(x^y)+2*x-a[i];
	}
}
signed main()
{
	int k,i;
	cin>>n>>k;
	for(i=3;i<=n;i+=3)
		get(i);
	sort(a+1,a+n+1);
	cout<<"finish "<<a[k]<<endl;
	return 0;
}
