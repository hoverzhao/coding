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
	unsigned int n;
	cin >> n;
	if (n == 2){ cout << 2; return 0;}
	unsigned int i;
	for ( i = 2; i * i <= n; i++ ) {
		int k = n % i;
		if (k == 0) {
			n = n / i;
			break;
		}
	}
	cout << n;
	return 0;
}

