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
	string s;
	cin >> n;
	cin >> s;
	int ans = 0;
	int i = s.find("VK");
	while (i != -1) {
		ans++;
		s[i] = 'T';
		s[i + 1] = 'T';
		i = s.find("VK", i + 1);
		//final 
	}
	
	//error VKK VVK KKV KVV 这些情况ans不该增加
	//error 考虑KKK VVV的情况，还要去掉首尾是KK VV的情况，是处理变复杂
	//使用标记改名的方式
	if ( (int)s.find("VV") != -1 || (int)s.find("KK") != -1)
		ans++;
	cout << ans ;

	return 0;
}
