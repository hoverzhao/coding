#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>

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
	string s, a;
	int i = 1, ans = 0;
	cin >> s;
	a = s;

	//删除相同的
	s.erase(remove(s.begin(), s.end(), '-'), s.end());
	
	while (i <= 9) {
		int a = s[i - 1] - '0';
		ans += a * i;
		i++;
	}
	ans %= 11;

	if ( (s[9] == 'X' ? 10 : s[9] - '0') ==  ans)
		cout << "Right";
	else {
		a[12] = ans < 10 ? ans + '0' : 'X';
		cout << a;
	}

	return 0;
}

