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
	string s{'a', 'b', 'c'};
	string s(4, '$');
	string s("I'm sorry, David.");

	s.find('r');
	s.rfind('r');
	s.find('X');
	s.find(' ', 5);
	s.substr(4, 6);

	s.contains("David.");
	s.starts_with("I");
	s.ends_with("David");

	s.clear();
	s.resize(3);
	s.resize(20, '?');

	s.append("..");
	s.insert(4, "very ");
	s.insert(begin(s), "HAL: ");
	
	s.erase(5, 2);
	s.erase(begin(s));
	s.erase(begin(s) + 4, begin(s) + 6);
	s.replace(11, 5, "Frand");


	string s("I'm sorry, David.");
	string s{'a', 'b', 'c'};
	string s(4, '$');

	s.clear();
	s.resize(3);
	s.resize(20, '?');

	s.find('r');
	s.rfind('r');
	s.find('X');
	s.find(' ', 5);
	s.substr(4, 6);

	s.contains("sorry");
	s.starts_with("I");
	s.ends_with("David.");
	s.compare("I'm sorry, Ane");

	s.clear();
	s.append("..");
	s.insert(4, "very ");
	s.insert(s.begin(), "HAL :");
	s.insert(s.begin() + 4, "very ");
	s.erase(5, 2);
	s.erase(s.begin() + 5);
	s.erase(s.begin(), s.begin() + 4);
	return 0;
}

