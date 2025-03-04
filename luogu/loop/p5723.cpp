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

	int L;
	cin >> L;
	int sum = 0, count = 0;
	
	for (int i = 2; sum <= L; i++) {
		int flag = 0;
		for (int j = 2; j * j <= i; j++)
			if (i % j == 0) {
				flag = 1;
				break;
			}

		if (!flag) {
			sum += i;
			if (sum <= L)
			{
				cout << i << endl;
				count++;
			}
		}
	}
	cout << count;

	return 0;
}

