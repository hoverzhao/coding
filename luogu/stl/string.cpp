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
	string s{'a', 'b', 'c'};
	string s{4, '$'};
	string s("I'm sorry, Dave.");

	//Assign
	
	//iterators
	s.begin(); s.end(); 
	s.rbegin(); s.rend();

	//size()
	s.resize(3);
	s.resize(20, '?');
	
	//capacity

	//search
	s.find('r');
	s.rfind('r');
	s.find('X');
	s.find(' ', 5);
	s.substr(4, 6);
	s.contains("Dave");
	s.starts_with('I');
	s.ends_with("Dave.");
	s.compare("I'm sorry, Ane."); // < 0;

	// add
	s.append("..");
	s.insert(4, "very ");
	s.insert(s.begin(), "HAL :");
	s.insert(s.begin() + 4, "very ");

	//erase
	s.clear();
	s.erase(5, 2);
	s.erase(s.begin()); //删除一个
	s.erase(s.begin(), s.begin() + 4);

	//modify
	s.replace(11, 5, "Frank");

	/* stoi stol stoll stoul stoull stof stod stold */
	/* to_string(xxx); */
	return 0;
}

