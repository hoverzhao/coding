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
	int a[12] = {0};

	int i = 0, ans = 0, cur = 0;
	while ( cin >> a[i] ) i++;
	for (i = 0; i < 12; i++) {
		cur += 300 - a[i];
		if (cur < 0) {
			cout << "-" << i + 1;
			return 0;
		}
		if (cur >= 100) {
			ans += cur - cur % 100;
			cur = cur % 100;
		}
	}
	cout << ans * 1.2 + cur << endl;

	return 0;
}

