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

int main() {
	//construct
	vector<int> v1{2, 9, 1, 8, 5, 4};
	vector<int> v2(begin(v1 + 3), end(v1));
	vector<int> v3(5, 3);	// 3 3 3 3 3
	vector<int> v{0, 1, 2, 3};

	//Assign
	v1 = v2;
	v.assign({4, 1, 3, 5});
	v.assign(2, 1);	//1 1
	v.assign(@InBeg, @InEnd);

	//iterators O(1);
	v.begin(); v.end();
	v.rbegin(); v.rend(); //+=2 ++
	v.rbegin().base(); v.rend().base();
	v.data(); // pointer to first
	//@pos = rev@pos.base() - 1;
	
	//size 
	v.empty();
	v.size();
	v.resize(3);
	v.resize(6, 1); // 0 1 2 3 1 1

	//capacity
	v.capacity();
	v.reserve(6); //memory buffer size
	vector<int> v(1024, 0);
	v.resize(40);	//capacity unchanged!
	v.shrink_to_fit(); // mayshrink
	v.swap(vector<int>(v));	//shrink but has copy overhead
	
	//search
	
	//add elem		O(n)
	v.push_back(7);
	v.insert(begin(v), 2);
	v.insert(begin(v), 3, 7); //	777xxxxxx
	v.insert(begin(v) + 1, {6, 9, 7});
	v.insert(begin(v) + 1, @InBeg, @InEnd);
	vector<pair<string, int>> v{{"a", 1}, {"w",7}};
	v.emplace_back("b", 4);
	v.emplace_back(begin(v) + 1, "z", 5);

	//erase elem	O(n)
	v.clear();
	v.pop_back();
	v.erase(begin(v) + 2);   // erase one
	v.erase(begin(v) + 1, begin(v) + 3);

	//modify elem	O(1)
	v[1] = 9;
	v.front() = 2;
	v.back() = 3;
	//out_of Bound Access
	v[100]; // undefined 
	v.at(100); //exception: out_of_range


	return 0;
}

