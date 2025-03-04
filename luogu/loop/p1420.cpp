#include <bits/stdc++.h>
#include <cmath>

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

int main() {
	int n;
	cin >> n;
	vector<int> a;
	while (n-- > 0) {
		
		int t;
		cin >> t;
		a.push_back(t);
	}
	int s = 1;
	int nmax = 1;
	for (size_t i = 0;  i < a.size(); i++) {
		int v = a[i];
		int k = i;
		while ( k + 1 < a.size() && a[k + 1] == v + 1) {
			/* cout << a[k]; */
			k++; v++; s++;
			/* cout << k; */
			/* cout << a[k - 1] << endl; */
		}
		if (nmax < s) nmax = s;
		s = 1;
	}
	cout << nmax;

	return 0;
}

