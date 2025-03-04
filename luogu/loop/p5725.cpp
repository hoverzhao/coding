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
	int n;
	cin >> n;
	int x = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++, x++ )
			cout << setfill('0') << setw(2) << x;
		cout << endl;
	}
	cout << endl;
	x = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++ ) {
			if (j <= n - i)
				cout << "  ";
			else
				cout << setfill('0') << setw(2) << x++;
		}
		cout << endl;
	}

	return 0;
}

