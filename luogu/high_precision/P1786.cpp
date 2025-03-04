#include <bits/stdc++.h>
using namespace std;

/* #ifdef ONLINE_JUDGE */
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "*" << #x << " -> "; err(x); } while (0)
void err() {cout << '\n'; }
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
	/* freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout); */
#endif
	return 0;
}();

/* #define LINF 0x3f3f3f3f3f3f3f3f */
#define INF  0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef long double ld;

/* map<string, int> titleinfo{{"BangZhu", 0},{"FuBangZhu", 1},{"HuFa", 5},{"ZhangLao", 4},{"TangZhu", 3},{"JingYing", 2},{"BangZhong", 1}}; */
vector<string>  tinfo {"BangZhu","FuBangZhu","HuFa","ZhangLao","TangZhu","JingYing","BangZhong"};
vector<int>		tcnt{1, 2, 2, 4 ,7, 25, 1000};


struct maninfo {
	string name;
	string title;
	int tid;
	ll	score;
	int level;
	int oldindex; // 旧的位置
};

vector<maninfo> raw_org;
vector<maninfo> org;  // the people collection of orignize;


bool score_sort(maninfo l, maninfo r) {
	if (l.score > r.score) return true;
	return false;
}

bool title_level_sort(maninfo l, maninfo r) {
	if (l.tid < r.tid) return true;
	if (l.tid == r.tid) {
		if (l.level > r.level) return true;
		if (l.level == r.level) {
			if(l.oldindex > r.oldindex) return true;
		}
	}
	return false;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		maninfo minfo;
		cin >> minfo.name >> minfo.title >> minfo.score >> minfo.level;
		minfo.oldindex = n - i;
		raw_org.push_back(minfo);
	}
	/* for (int i = 0; i < n; i++) { */
	/* 	maninfo m = raw_org[i]; */
	/* 	cout << m.score << ' '; */
	/* 	cout << m.name << ' ' << m.title << ' ' <<  m.level << '\n'; */
	/* } */

	stable_sort(raw_org.begin() + 3, raw_org.end(), score_sort);

	int k = tcnt[0];
	for (int i = 0, j = 0 ; i < n; i++) {
		if (i >= k) { k += tcnt[++j]; }
		raw_org[i].title = tinfo[j];
		raw_org[i].tid = j;
	}

	stable_sort(raw_org.begin() , raw_org.end(), title_level_sort);

	for (int i = 0; i < n; i++) {
		maninfo m = raw_org[i];
		/* cout << m.score << ' '; */
		cout << m.name << ' ' << m.title << ' ' <<  m.level << '\n';
	}
	return 0;
}


