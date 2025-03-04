
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
	int a[101] = {};
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int sum = a[i] + a[j];
			if (find (a, a+n, sum) != a+n) {
				auto num = find (a, a+n, sum);
				if (*num != a[i] && *num != a[j]) {
					/* cout << a[i] << '+' << a[j] << '=' << sum << endl; */
					ans++;
				}
			}
			/* for (int k = 0; k < n; k++) { */
			/* 	if (k == i || k == j) */
			/* 		continue; */
			/* 	if (a[i] + a[j] == a[k]) */
			/* 		ans++; */
			/* } */
		}
	}
	cout << ans;
	return 0;
}
