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
	int b, a[100];
	string s;
	cin >> s >> b;
	size_t n = s.size();

	for (size_t i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}

	int t = 0;
	bool flag = true;
	for (size_t i = 0; i < n; i++) {
		t = t * 10 + a[i];
		if (flag && t / b != 0 && i > n - 1) continue;
		flag = false;
		cout << t / b;
		t %= b;
	}
}
