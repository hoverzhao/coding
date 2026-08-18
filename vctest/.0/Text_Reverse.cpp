#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	return 0;
}();

const int N = 1010;

struct sstack {
	int t;
	char a[N];
	char top()			{ return a[t];}
	void push(char e)	{ a[++t] = e;	}
	void pop()			{ t--; }
	bool empty()		{ return (t == 0) ? true : false;}
	void clear()		{ t = 0;}
};


int main() {
	int n; cin >> n;
	cin.ignore();
	char c;
	sstack st;
	while (n--) {
		st.clear();
		while (true) {
			cin.get(c);
			if (c == ' ' || c == '\n' || c == EOF) {
				while(!st.empty()) { cout << st.top(); st.pop();}
				if (c == '\n' || c == EOF) break;
				cout << ' ';
			} else {
				st.push(c);
			}
		}
		cout << endl;
	}
	return 0;
}