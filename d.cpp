#include "bits/stdc++.h"
#include "bits/competitive.h"
using namespace std;

static int x = []() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("d.in", "r", stdin); 
	freopen("d.out", "w", stdout);
	return 0;
}();

int main(int argc, char *argv[]) {
	if (argc > 1) {
		int a = atoi(argv[1]);
	}
	int a, b;
	cin >> a >> b;
	cout << a + b << endl;

	return 0;
}


