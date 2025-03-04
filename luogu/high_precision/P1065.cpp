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

struct item {
	int mid;
	int time;
};

int n, m;
const int MAXTIME = 50000;
vector<int> seq;			//输入的工序序列


int main() {

	cin >> m >> n;

	int t = m * n;
	while (t--) {int i = 0; cin >> i; seq.push_back(i); }

	vector<int> istep(n, 0);	// 工件进行到的工序
	vector<int> iend(n, 0);		// 工件已经加工的时间
	vector<vector<int>> has_in_use(m, vector<int>(MAXTIME, 0)); // machine time line


	vector<vector<item>> vi(n, vector<item>(m, {0, 0}));
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			cin >> vi[a][b].mid; 
		}
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			cin >> vi[a][b].time; 
		}
	}

	auto check = [&](int mid, int begintime, int duration) -> bool {
		for (int i = begintime; i < begintime + duration; i++) {
			if (has_in_use[mid][i] == true)
				return false;
		}
		return true;
	};


	int ans = -1; // 求最小时间
	for (int i  = 0; i < (int)seq.size(); i++) {
		int id, step, mid, time;    
		id		= seq[i] - 1;	//工件号
		step	= istep[id]++ ;	//工序号
		mid		= vi[id][step].mid - 1; //机器号
		time	= vi[id][step].time; //工序时间
		/* dbg(id, step, mid, time); */

		for (int k = iend[id];; k++) {
			if (check(mid, k, time)) {
				iend[id] = k + time;
				if (iend[id] > ans ) ans = iend[id];
				for (int z = k; z < k + time; z++) {
					has_in_use[mid][z] = true; 
				}
				break;
			}
		}
	}
	cout << ans <<'\n';
	return 0;
}


/* 1 1 2 3 3 2 */
/* 1 3 1 2 2 3 */
