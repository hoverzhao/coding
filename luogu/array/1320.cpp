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

/* int s[200][200] = {}; */
int r[40000] = {};
string s[200] = {};
int main() {
	int n = 0;
	while (cin >> s[n++]);
	// error: cout << n;
	--n;
	cout << n << " ";

	int la = 0, lb = 0;

	int cnt = 0;
	int i = 0;

	// error 第一位为一的情况
	if (s[0][0] == '1') {
		cout << cnt << " ";
		//error:2 计数增加
		cnt++;
		i++;
	}

	while (i < n * n) {
		int a = i / n;
		int b = i % n;
		if (s[a][b] != s[la][lb]) {
			cout << cnt << " ";
			cnt = 0;
		}
		cnt++;
		la = a;
		lb = b;
		i++;
	}
	//error  忘写这行
	cout << cnt << " ";
	
	return 0;
}

