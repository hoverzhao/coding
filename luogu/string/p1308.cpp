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
//需要学习 状态机解法

int main() {
	string str, line;
	int cnt = 0;
	cin >> str;
	cin.ignore();
	getline(cin, line);

	//error 必须用全局toupper
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	transform(line.begin(), line.end(), line.begin(), ::toupper);
	line = " " + line + " ";
	str = " " + str + " ";
	/* size_t line_size = line.size(); */
	size_t str_size = str.size();

	int start = line.find(str);
	size_t k = start;

	/* while (k != string::npos && k + str_size < line_size) { */
	while (k != string::npos) {
		// error: loop forever
		/* k = line.find(str, k) + str_size; */
		// error:  baba bababa
		k = line.find(str, k + str_size);
		/* k = line.find(str, k + 1) ; */
		cnt++;
	}

	if (cnt != 0)
		cout << cnt << " " << (int)start;
	else
		cout << -1;


	/* 	//error: find返回的是字首位置,所以下次寻找要从+字符长度 */
			/* i = k + str_size; */
			/* k = s.find(str, i); */

	//error ? : 语句，必须做类型转化
	/* cout << cnt << " " << (int)(start == string::npos ? -1 : start); */
	return 0;
}

