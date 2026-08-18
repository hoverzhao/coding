#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	return 0;
}();

const int N = 1000100;
int a[N];
int s[2*N] = {0};
deque<int> q;

int main() {
	int n, m; cin >> n; m = n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {cin >> s[i]; s[i + n] = s[i];}
	for (int i = 1; i <= 2*n; i++) s[i] += s[i-1];
	for (int i = 1; i < 2*n; i++) {
		while (!q.empty() && s[q.back()] > s[i]) q.pop_back();
		q.push_back(i);
		if (i <= m) {
			while (!q.empty() && q.front() <= i-m) q.pop_front();
			if (s[q.front()] - s[i-m] >=0) {
				ans++; 
			}
		}
	}
	// cout << endl;
	cout << ans;
	return 0;
}
