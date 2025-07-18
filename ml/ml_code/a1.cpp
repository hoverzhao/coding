#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	std::string s;
	std::cin >> s;

	std::cout << *std::min_element(s.begin(), s.end()) << "\n";
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
//By *jiangly, contest: Codeforces Round 1037 (Div. 3), problem: (A) Only One Digit,
//https://codeforces.com/contest/2126/problem/A
