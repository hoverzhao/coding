#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> l(n), r(n), real(n);
	for (int i = 0; i < n; i++) {
		std::cin >> l[i] >> r[i] >> real[i];
	}

	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);
	std::sort(p.begin(), p.end(),
		[&](int i, int j) {
			return real[i] < real[j];
		});
	for (auto i : p) {
		if (l[i] <= k && k < real[i]) {
			k = real[i];
		}
	}
	std::cout << k << "\n";
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

//By *jiangly, contest: Codeforces Round 1037 (Div. 3), problem: (D) This Is the Last Time
//https://codeforces.com/contest/2126/problem/D
