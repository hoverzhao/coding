#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	mt19937 rnd((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
	int a = rnd() % 1000;
	int b = rnd() % 1000;
	cout << a << ' '  << b;
	return 0;
}
