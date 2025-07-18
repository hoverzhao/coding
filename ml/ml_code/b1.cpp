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

	std::vector<int> s(n + 1);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}

	int ans = 0;
	int x = 0;
	while (x + k <= n) {
		if (s[x + k] == s[x]) {
			x += k + 1;
			ans++;
		} else {
			x++;
		}
	}
	std::cout << ans << "\n";
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
//By *jiangly, contest: Codeforces Round 1037 (Div. 3), problem: (B) No Casino in the Mountains
//https://codeforces.com/contest/2126/problem/b
