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
	string b;
	getline(cin, b);
	/* cin >> n; */
	n = stoi(b);
	// error cin 和getline 不能混用
	/* cin.ignore(); */
	/* cin.ignore(); */

	vector<vector<string>> s;
	string tmp = {}; string t2 = {};
	while (n--) {
		getline(cin, tmp); 
		//error 大坑 洛谷数据文件使用windows \n\r 换行，而linux使用\n换行
		if (tmp[tmp.size() - 1] == '\r') tmp.erase(tmp.size() - 1); 
		istringstream input(tmp);
		vector<string> v;
		while (getline(input, t2,' ')) {
			v.push_back(t2);
		}
		s.push_back(v);
	}

	string key = {}, ans = {};
	unsigned long cnt = 0;
	
	for (auto m : s) {
		int i = 0; 
		if (m.size() == 3) {
			key = m[0];
			i = 1;
		}
		if (key == "a") {
			ans = m[i] + "+" + m[i + 1] + "=" + to_string((long long)(stoll(m[i]) + stoll(m[i + 1])));
		}
		if (key == "b") {
			ans = m[i] + "-" + m[i + 1] + "=" + to_string((long long)(stoll(m[i]) - stoll(m[i + 1])));
		}
		if (key == "c") {
			ans = m[i] + "*" + m[i + 1] + "=" + to_string((long long)(stoll(m[i]) * stoll(m[i + 1])));
		}
		if (cnt == s.size() - 1)
			cout <<ans << endl << ans.size();
		else
			cout <<ans << endl << ans.size() << endl;
		cnt++;
	}

	return 0;
}

