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
	string str = "one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty";
	istringstream is(str);
	map<string, int> dic;
	string s;
	int i = 1;
	while (getline(is,s, ' ')) {
		/* cout << s << endl; */
		dic.insert(make_pair(s, i++));
		/* cout << dic[s] << endl; */
	}
	dic.insert(make_pair("another", 1));
	dic.insert(make_pair("both", 2));
	dic.insert(make_pair("a", 1));
	dic.insert(make_pair("first", 1));
	dic.insert(make_pair("second", 1));
	dic.insert(make_pair("third", 1));
	string source = {};
	getline(cin, source);
	/* cout << "** " << source << endl; */
	char c = ::tolower(source[0]);
	source[0] = c;

	vector<int> list;

	istringstream sin(source);
	string st;

	//error 使用geline 而不是cin 因为有空格； getline 第三个参数为空格
	while(getline(sin, st, ' ')) {
		if (st == ".") break;
		if (dic.find(st) != dic.end()) {
			/* cout << " dic[st]=" << dic[st] << endl; */
			int k = (dic[st] * dic[st]) % 100;
			list.push_back(k);
		}
	}

	sort(list.begin(), list.end());
	
	string ans = {};
	for (auto v : list) {
		/* cout << v << endl; */
		if (v == 0) continue;
		if (v <= 9) ans += "0" + to_string(v); 
		else ans += to_string(v);
		/* cout << ans << endl; */
	}
	if (ans.empty()) {
		cout << 0 ;
		return 0;
	}
	if (ans[0] == '0')
		ans.erase(0, 1);
	cout << ans;
	return 0;
}
