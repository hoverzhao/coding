#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;


static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();

struct robot {
	int dir;
	string name;
};

int main() {
	vector<robot> vt;
	robot rt;
	int n, m;
	cin >> n >> m;
	int pos = 0;
	while (n--) {cin >> rt.dir >> rt.name; vt.push_back(rt);}
	int i = 0;
	/* cout << vt.size(); */
	n = vt.size();
	while (m--) {
		int d, step;
		cin >> d >> step;
		step %= n;
		int p = d ^ vt[pos].dir ? 1 : -1;
		pos += p * step;
		pos = pos < 0 ? pos + n : pos;
		pos = pos >= n ? pos - n : pos;
	}
	cout << vt[pos].name;
}

