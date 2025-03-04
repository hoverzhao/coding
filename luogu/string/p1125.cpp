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

int cnt[26] = {};
int main() {
	string s;
	cin >> s;
	for (auto v : s) 
		cnt[v - 'a']++;
	
	int min = INF,max = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) continue;
		if (min > cnt[i]) min = cnt[i];
		if (max < cnt[i]) max = cnt[i];
	}
	/* cout << "max = " << max << " min = " << min << endl; */
	int nb = max - min;

	bool bzhishu = true;
	for (int i = 2; i * i <= nb; i++) {
		if ( nb % i == 0 ) {
			bzhishu = false;
			break;
		}
	}
	if ( nb == 0 || nb == 1)
		bzhishu = false;

	if (bzhishu) {
		cout << "Lucky Word" << endl;
		cout << nb;
	} else {
		cout << "No Answer" << endl;
		cout << 0;
	}
	return 0;
}

