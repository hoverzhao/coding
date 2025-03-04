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

/* int a[3];char s1,s2; */
/* int main() */
/* { */
/*     while (scanf("%c:=%c;",&s1,&s2)==2)//充分利用c++语言优势 */
/*      a[s1-'a']=s2>='0' && s2<='9' ? s2-'0' : a[s2-'a']; //赋值语句简洁明了 */
/*     printf("%d %d %d",a[0],a[1],a[2]); */
/* } */

string s = {};
int getvalue(char a) {

	size_t p = s.find_last_of(a);
	int v = 0;
	char b = a;
	while (p != string::npos) {
		int i = p % 5;
		// 左值
		if (i == 0) {
			if (isdigit(s[p + 3])) {
				v = s[p + 3] - '0';
				break;
			} else {
				//这里不判0会死循环，因为rfind(*,-1) 不会返回npos
				if (p == 0) break;
				b = s[p + 3];
				p = s.rfind(s[p + 3], p - 1);
			}
		} else {
			p = s.rfind(b, p - 1);
		}
	}
	return v;
}

int main() {
	cin >> s;
	cout << getvalue('a') << " ";
	cout << getvalue('b') << " ";
	cout << getvalue('c');

	return 0;
}
