#include <bits/stdc++.h>
using namespace std;

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

int main() {

	cin >> m >> n;
	int t = m * n;

	vector<int> seq;
	vector<vector<item>> vi(n, vector<item>(m, {0, 0}));

	while (t--) {int i = 0; cin >> i; seq.push_back(i); }
	sort(seq.begin(), seq.end());
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

	int mintime = INF;
	vector<int> end_seq;

	do {
		/* fill(vstep.begin(), vstep.end(), 0); */
		vector<int> vstep(n, 0); // 工序到那个阶段了
		vector<int> vmt(m, 0); // 机器结束时间
		vector<int> vit(n, 0); // 工序结束时间
		int id, step, mid, starttime, endtime, maxtime = -1;
		for (int i = 0; i < (int)seq.size(); i++) {
			id		= seq[i] - 1;
			step	= vstep[id];
			mid		= vi[id][step].mid - 1;

			starttime = max(vmt[mid], vit[id]); 
			
			endtime = starttime + vi[id][step].time;
			vmt[mid] = endtime;
			vit[id]  = endtime;
			if (maxtime < endtime)
				maxtime = endtime;

			/* dbg(id, step, mid, starttime, endtime); */
			vstep[id]++;
		}
		/* dbg(totaltime); */
		if (mintime > maxtime) {
			mintime = maxtime;
			end_seq = seq;
		}

	} while (next_permutation(seq.begin(), seq.end()));
/* } while (0); */

	cout << mintime << '\n';
	/* cout << count << '\n'; */
	for (auto v : end_seq)
		cout << v << ' ';
	return 0;
}
