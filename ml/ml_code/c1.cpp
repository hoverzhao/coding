#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int s = a[k - 1];
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] >= s) {
			if (a[i + 1] - a[i] > s) {
				std::cout << "NO\n";
				return;
			}
		}
	}
	std::cout << "YES\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}

//By *jiangly, contest: Codeforces Round 1037 (Div. 3), problem: (C) I Will Definitely Make It
//https://codeforces.com/contest/2126/problem/C
