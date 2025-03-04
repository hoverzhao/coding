#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
mt19937 rnd((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

static int x = []() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("xxx.in", "r", stdin); 
	freopen("xxx.out", "w", stdout);
	return 0;
}();

int main() {
	int a, b;
	cin >> a >> b;
	cout << a + b << endl;

	return 0;
}
