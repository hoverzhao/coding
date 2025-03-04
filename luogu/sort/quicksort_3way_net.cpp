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


void partition(int arr[],int left,int right,int &i,int &j)
{
	i=left-1,j=right;
	int p=left-1,q=right;
	int v=arr[right];
	while(true) 
	{
		while(arr[++i]<v);
		while(v<arr[--j])
		{
			if(j==left)
				break;
		}
		if(i>=j)
			break;
		swap(arr[i],arr[j]);
		if(arr[i]==v) 
			swap(arr[++p],arr[i]);
		if(arr[j]==v)
			swap(arr[j],arr[--q]);
	}
	swap(arr[i],arr[right]);
	j=i-1;
	for(int k=left;k < p; k++, j--)
		swap(arr[k],arr[j]);
	i=i+1;
	for(int k=right-1;k>q;k--,i++)
		swap(arr[i],arr[k]);
}
/*
3-way partition based quicksort logic->
			arr[left..i] < pivot
			arr[i+1..j-1] = pivot
			arr[j..right] > pivot 
*/
void quicksort(int arr[],int left,int right)
{
	if(right<=left)
		return;
	int i=0,j=0;
	partition(arr,left,right,i,j);
	quicksort(arr,left,j);
	quicksort(arr,i,right);
}

int main()
{
	int n;
	cout<<"Enter the size::"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements::"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<endl<<"The stored values::"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	quicksort(arr,0,n-1);//'n-1' is passed as parameter as last index of array will be n-1
	cout<<endl<<"The sorted values are::"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
return 0;
}
