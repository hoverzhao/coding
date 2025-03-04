#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;


static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();


//error: 为考虑到大于11的情况
/* void showMatchOver(int n, vector<string> const &vs) { */
/* 	int i = 0; */
/* 	int j = 0; */
/* 	auto p  = [&](){ cout << i << ":" << j << endl; i = 0; j = 0;}; */
/* 	for (string s : vs) { */
/* 		size_t len = s.size(); */
/* 		size_t k = 0; */
/* 		while(k < len) { */
/* 			if (i < n && s[k] == 'W') i++; */
/* 			else if (i == n) { p(); continue;} */
/* 			else if (j < n && s[k] == 'L') j++; */
/* 			else if (j == n) { p(); continue;} */
/* 			else if (s[k] == 'E') { p(); return;} */ 
/* 			k++; */
/* 		} */
/* 	} */
/* } */

//error 处理大于11 边界条件没有前置，导致判断复杂，错误频出
/* void showMatchOver(int n, vector<string> const &vs) { */
/* 	int i = 0; */
/* 	int j = 0; */
/* 	auto p  = [&](){ cout << i << ":" << j << endl; i = 0; j = 0;}; */
/* 	for (string s : vs) { */
/* 		size_t len = s.size(); */
/* 		size_t k = 0; */
/* 		while(k < len) { */
/* 			if		(i < n	&& s[k] == 'W') i++; */
/* 			else if (i >= n && abs(i - j) <  2 && s[k] == 'W') i++; */
/* 			else if (i >= n && abs(i - j) >= 2 && s[k] == 'W') { p(); continue;} */
/* 			else if (j < n	&& s[k] == 'L') j++; */
/* 			else if (j >= n && abs(i - j) <  2 && s[k] == 'L') j++; */
/* 			else if (j >= n && abs(i - j) >= 2 && s[k] == 'L') { p(); continue;} */
/* 			else if (s[k] == 'E') { p(); return;} */ 
/* 			k++; */
/* 		} */
/* 	} */
/* } */

void showMatchOver(int n, vector<string> const &vs) {
	int i = 0;
	int j = 0;
	auto p  = [&](){ cout << i << ":" << j << endl; i = 0; j = 0;};
	for (string s : vs) {
		size_t len = s.size();
		size_t k = 0;
		while(k < len) {
			// 总结边界前置可以极大的简化判断逻辑
			// error： 修改：下两行顺序交换后可以通过 11:0 0:0的情况
			if ( (i >= n || j >= n) &&  abs(i - j) >= 2 ) {p(); continue;}
			if (s[k] == 'E') {p(); return ;}

			if		(s[k] == 'W') i++;
			else if (s[k] == 'L') j++;
			k++;
		}
	}
}

int main() {
	vector<string> vs;
	string s;
	while (getline(cin, s)) vs.push_back(s);
	showMatchOver(11, vs);
	cout << endl;
	showMatchOver(21, vs);

	return 0;
}

