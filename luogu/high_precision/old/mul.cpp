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
	int a[100] = {0}, b[100] = {0}, c[205] = {0};
	string sa, sb;
	cin >> sa >> sb;
	for (size_t i = 0; i < sa.size(); i++) {
		a[i] = sa[sa.size() - i - 1] - '0';
	}
	for (size_t i = 0; i < sb.size(); i++) {
		b[i] = sb[sb.size() - i - 1] - '0';
	}

	int n = sa.size();
	int m = sb.size();
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			c[i + j] += a[i] * b[j];

	int t = m + n;
	for (int k = 0; k < t; k++) {
		c[k + 1] += c[k] / 10;
		c[k] = c[k] % 10;
	}
	while ( c[t] == 0 && t > 0) t--;
	while ( t >=0 ) cout << c[t--];
	return 0;
}

