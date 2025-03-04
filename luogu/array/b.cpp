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

int main() {
	int n;
	int s[33] = {};
	int ans[1000] = {};

	cin >> n;
	for (int i = 0; i < 7; i++) { int t; cin >> t; s[t] = 1;}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) { 
			int t; 
			cin >> t;
			if (s[t] == 1)
				ans[i]++;
		}
	}
	sort(ans, ans + n);
	int bns[8] = {};
	for (int i = 0; i < n; i++) {
		bns[ans[i]]++;
	}
	for (int i = 7; i > 0; i--) {
		cout << bns[i] << " ";
	}


	

	return 0;
}

