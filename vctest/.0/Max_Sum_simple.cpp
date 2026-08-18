
// #include <bits/stdc++.h>
#include <iostream>
#include <deque>
using namespace std;

static int x = []() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}();

const int INF = 1e5 + 10;

void solve() {
		int n; cin >> n;
		int start=1, end=1, p=1;
		int sum = 0;
		int maxsum = -INF;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			sum += a;
			if (maxsum < sum) {
				start = p; end = i; maxsum = sum;
			}
			if (sum < 0) {
				sum = 0; p = i + 1;
			}
		}
		cout << maxsum << ' ' << start << ' ' << end << '\n';
}

int main() {
	int t; cin >> t;
	int k = 1;
	while (t--) {
		cout << "Case " << k++ << ":" << '\n';
		solve();
		cout << endl;
	}
	return 0;
}