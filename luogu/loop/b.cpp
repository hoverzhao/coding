#include <bits/stdc++.h>

#define ll	long long
#define INF 0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();

void pvec(vector<int> &v) {
	int t = v.size();
	while (v[t] == 0 && t > 0) t--;
	while (t >= 0) cout << v[t--];
	cout << endl;
}

int main() {
	vector<int> a = {9, 9, 9};
	vector<int> b = {8, 8, 8};
	pvec(a);
	pvec(b);
}

