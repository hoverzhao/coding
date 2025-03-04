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

int s[200][200] = {};
int r[40000] = {};
int main() {
	int n;
	cin >> n;

	int index = 0;
	while (cin >> r[index++]);
	int k = 0;
	int cnt = -1;
	bool step0 = true;
	while (k < index) {
		int t = r[k];
		//易错点 t >= 0 
		while ( t > 0) {
			//易错点 == n
			if (cnt == n - 1) {
				cnt = 0;
				cout << endl;
			} else {
				cnt++;
			}
			if (step0 == true) {
				cout << 0;
			} else {
				cout << 1;
			}
			--t;
		}
		++k;
		step0 = !step0;
	}
	
	return 0;
}

