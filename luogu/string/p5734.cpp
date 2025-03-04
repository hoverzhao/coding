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
	int n;
	cin >> n;
	string str;
	cin >> str;
	while (n--) {
		string opt = {};
		string p1 = {}, p2 = {};
		int t1 = 0, t2 = 0;
		cin >> opt;
			if (opt == "1") {
				cin >> p1;
				str.append(p1);
				cout << str << endl;
			}
			if (opt == "2") {
				cin >> t1;
				cin >> t2;
				//error
				//str.substr(t1, t2);
				str = str.substr(t1, t2);
				cout << str << endl;
			}
			if (opt == "3") {
				cin >> t1;
				cin >> p1;
				str.insert(t1, p1);
				cout << str << endl;
			}
			if (opt == "4") {
				cin >> p1;
				if (str.find(p1) == string::npos)
					cout << -1 << endl;
				else
					cout << str.find(p1) << endl;
			}
	}
	return 0;
}

