#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	return 0;
}();

int main() {
	int n, m;
	cin >> n >> m;
	int a[100];
	for (int i = 1; i <= n; i++) a[i] = i + 1;
	a[n] = 1;
	int now = 1, pre = 1;
	while (n-- >= 1) {
		for (int i = 1; i < m; i++) {
			pre = now; now = a[now];
		}
		cout << now << ' ';
		a[pre] = a[now];
		now = a[now];
	}
	return 0;
}