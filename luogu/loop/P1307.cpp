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
	string s;
	cin >> s;
	if (s[0] == '-')
		reverse(s.begin() + 1, s.end());
	else
		reverse(s.begin(), s.end());
	ll v = stoll(s);
	cout << v;
	return 0;
}

