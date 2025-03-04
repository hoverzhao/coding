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
	vector<int> v{1, 2, 3, 4, 5, 6};
	vector<int> v(5, 3);
	vector<int> v2(begin(v) + 3, end(v));
	//assign
	v = v2;
	v.assign({1, 2, 3, 4});
	v.assign(5, 3);
	v.assign(@InBeg, @InEnd);
	//iterator
	v.begin(); v.end();
	v.rbegin().base(); v.rend().base();
	v.data();
	//size
	v.empty();
	v.size();
	v.resize(3);
	v.resize(6, 1);
	//capacity
	v.capacity();
	v.reverse(10);
	vector<int> v(1024, 0);
	v.resize(10);
	v.shrink_to_fit();
	v.swap(vector<int>(v));
	//search
	//add
	v.push_back(6);
	v.insert(begin(v), 2);
	v.insert(begin(v), 3, 8);
	v.insert(begin(v) + 1, {6, 9, 7});
	v.insert(begin(v) + 1, @InBeg, @InEnd);
	vector<pair<string, int>> v{{"a", 1}, {"b", 2}};
	v.emplace_back("c", 3);
	v.emplace_back(v.begin() + 1, "c", 3);
	//erase
	v.clear();
	v.erase(begin(v) + 2);
	v.erase(begin(v), begin(v) + 3);
	//modify
	v[1] = 9;
	v.front() = 2;
	v.end() = 3;
	v[100];
	v.at(100);
	return 0;
}

