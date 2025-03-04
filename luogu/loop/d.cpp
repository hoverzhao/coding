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

int a[101] = {0}, b[101] = {0};

int main() {
	int n, i, j;
	cin >> n;
	b[0] = 1;
	a[0] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 0; j < 100; j++) 
			b[j] *= i;
		for (j = 0; j < 100; j++) 
			if (b[j] > 9) {
			b[j + 1] += b[j] / 10;
			b[j] %= 10;
		}
		for (j = 0; j < 100; j++)
			a[j] += b[j];
		for (j = 0; j < 100; j++)
			if (a[j] > 9) {
				a[j + 1] += a[j] / 10;
				a[j] = a[j] % 10;
			}
	}
	for (i = 100; i >= 1 && a[i] == 0; i--);
	while (i >= 0) cout << a[i--];
	return 0;
}

