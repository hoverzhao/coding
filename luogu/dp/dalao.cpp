#include <bits/stdc++.h>

#define ll	long long
#define INF 0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	/* freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout); */
#endif
	return 0;
}();

int main() {
	int n;
	cin >> n;
	int a[100] = {};
	int re[20000];
	int len = 0;
	while (len < n) {
		cin >> a[len];
		len++;
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if ( i == j) continue; 
			re[a[i] + a[j]] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (re[a[i]] == 1) ans++; 
	}
	cout << ans++;
	return 0;
}

