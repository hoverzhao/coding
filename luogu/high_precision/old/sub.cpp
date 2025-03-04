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
	int a[100] = {0}, b[100] = {0}, c[101] = {0};
	string sa, sb;
	cin >> sa >> sb;
	
	for (size_t i = 0; i < sa.size(); i++) {
		a[i] = sa[sa.size() - i - 1] - '0';
	}
	for (size_t i = 0; i < sb.size(); i++) {
		b[i] = sb[sb.size() - i - 1] - '0';
	}

	int n = max(sa.size(), sb.size());
	
	for (int i = 0; i < n; i++) {
		a[i + 1] += (a[i] - b[i] - 9) / 10;
		 c[i] = (a[i] - b[i] + 10) % 10;
	}
	while (n > 0 && c[n] == 0) n--;
	while (n >= 0) cout << c[n--];

	return 0;
}

