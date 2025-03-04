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
	float dis;
	cin >> dis;
	if ( dis <= 2 ) { cout << 1; return 0;}

	double base = 2;
	double sum = 2;

	ll i;
	for (i = 1; sum < dis; i++) {
		base *= 0.98;
		sum += base;
	}
	cout << i;
	return 0;
}

