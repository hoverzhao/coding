#include <bits/stdc++.h>
#include <random>
using namespace std;


int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n = rng() % (6 - 3 + 1) + 3;
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		ostringstream os;
		os << setw(3) << setfill('0') << i + 1 << ' ';
		cout << "name" << os.str() << ' ';
		cout << "title" << ' ' ;
		int level = rng() % 150 + 1;
		// 0 10 100... 10^9;
		int index = rng() % 10;
		long long score = pow(10,index); 
		cout << score << ' ';
		cout << level << '\n';
	}

	return 0;
}

