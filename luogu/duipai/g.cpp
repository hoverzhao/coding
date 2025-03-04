#include <bits/stdc++.h>
#include <random> 

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	/* srand(time(0)); */

	mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

	//产生1-20之间的数字
	int a = rng () % 20 + 1;
	int b = rng () % 20 + 1;
	cout << a << ' ' <<  b;
	return 0;
}

