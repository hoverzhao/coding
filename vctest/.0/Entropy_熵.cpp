#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	return 0;
}();

priority_queue<int, vector<int>, greater<int> > q;

int main() {
	string s;
	while (getline(cin, s) && s != "END") {
		int num = 1;
		int ans = 0;

		sort(s.begin(), s.end());

		for (int i = 1; i <= s.length(); i++) {
			if (s[i] != s[i-1]) {
				q.push(num);
				num = 1;
			} else {
				num++;
			}
		}

		if (q.size() == 1) ans = s.length();
		while (q.size() > 1) {
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			ans += a + b;
			q.push(a+b);
		}

		q.pop();

		cout << s.length() * 8 << ' '
		<< ans << ' '
		<< fixed << setprecision(1)
		<< (double)s.length() * 8/ (double)ans << endl;
	}
	return 0;
}