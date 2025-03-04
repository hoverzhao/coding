#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int INF = 1e9;
double ESP = 1e-9;

static int x = []() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("t270955.in", "r", stdin);
	freopen("t270955.out", "w", stdout);
	return 0;
}();



int main() {
	ll x, k;
	cin >> x >> k;
	
	if (k > 40) cout << 1;
	else {
		int t = x % 3;
		while (k--) {
			int t = x 	
		}
		ll ans = x / 3 + 1;
		while (--k) {
			ans = ans / 3 + 1;
		}
		cout << ans;
	}
	// 0 , 1, 2;
	/* switch (m) { */
	/* 	case 0: */

	/* } */
	return 0;
}

