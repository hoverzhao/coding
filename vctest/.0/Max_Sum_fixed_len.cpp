
// #include <bits/stdc++.h>
#include <iostream>
#include <deque>
using namespace std;

static int x = []() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}();
const int INF = 1e6 +7;
const int N = 100100;
int s[N] = {0};
deque<int> q;
void solve() {
	int n; cin >> n;
	int m = n;
	int maxsum = -INF;
	int nstart=1, nend=1;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) s[i] += s[i-1];
	q.push_back(0);
	for (int i = 1;  i <= n; i++) {
		while (!q.empty() && q.front() < i-m) q.pop_front();
		int sum = s[i] - s[q.front()];
		if (maxsum < sum) {
			nstart = q.front() + 1;
			nend = i;
			maxsum = sum;
		}
		while(!q.empty() && s[q.front()] > s[i]) q.pop_back();
		q.push_back(i);
	}
	cout << maxsum << ' ' << nstart << ' ' << nend << ' ' << endl;
}

int main() {
	int T;  cin >> T;
	int cid = 1;
	while (T--) {
		cout << "Case " << cid++ << ":" << endl; 
		solve();
		cout << endl;
	}
	return 0;
}