#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	return 0;
}();

const int N = 1e5 + 10;

struct sstack {
	int a[N];
	int t;
	int top() { return a[t];}
	void push(int e) { a[++t] = e;}
	void pop() { --t; }
	bool empty() {return (t==0) ? true : false;}
	void clear() { t = 0;}
};

int h[N] = {0};
int ans[N] = {0};

int main() {
	int n; cin >> n;
	sstack st;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && h[i] >= h[st.top()]) st.pop();
		if (st.empty()) ans[i] = 0;
		else ans[i] = st.top();
		st.push(i);
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}