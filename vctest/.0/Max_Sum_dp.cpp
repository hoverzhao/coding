
// #include <bits/stdc++.h>
#include <iostream>
#include <deque>
using namespace std;

static int x = []() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}();

const int INF = 1e6 + 10;
const int N = 1e5 + 10;
int dp[N];

void solve() {
	int n; cin >> n;
	int start=1, end=1, p=1;
	int maxsum = -INF;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
		if (dp[i-1] >= 0)
			dp[i] += dp[i-1];
		else {
			p = i;
		}
		if (maxsum < dp[i]) {
			maxsum = dp[i];
			start = p; end = i;
		}
	}
	cout << maxsum << ' '
	<< start << ' '
	<< end << ' ' << endl;
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