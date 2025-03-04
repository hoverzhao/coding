#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define eb emplace_back
#define mp make_pair
typedef long long ll;
typedef long double ld;

using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();

vector<int> mul_2(vector<int> const &a, vector<int> const &b) {
	vector<int> c((int)a.size() + (int)b.size());
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < (int)b.size(); j++) {
			if (i + j > 500) continue;
			c[i + j] += a[i] * b[j];
		}
	}
	int t = 0;
	for (int i = 0; i < (int)c.size(); i++) {
		t += c[i];
		c[i] = t % 10;
		t /= 10;
	}
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}

int main() {
	int p;
	vector<int> a(501, 0);
	vector<int> c(502, 0);
	a[0] = 2;
	c[0] = 1;
	cin >> p;
	cout << (int)(floor(log10(2) * p) + 1) << '\n';
	while(p) {
		if (p & 1)
			c = mul_2(a, c);
		a = mul_2(a, a);
		p >>= 1;
	}
	c[0]--;
	int t = 0;
	for (int i = 499; i >= 0; i--) {
		if (t == 50) {
			t = 0;
			cout << '\n';
		}
		cout << c[i];
		t++;
	}
	return 0;
}

