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

//1.打表法
// ...............
//
//2.生成法
int s[10] = {0}, a, b;
bool bValid = true;
bool isPrime(ll n) {
	for (int i = 2; i * i <= n; i++) 
		if (n % i == 0) 
			return false;
	return true;
}

void Gen(int pos, int len) {

	int halflen = (len - 1) / 2;
	if (pos <= halflen) {
		for (int i = 0; i < 10; i++)
		{
			if (pos == 0 && (i == 0 || i % 2 == 0)) continue;
			s[pos] = i;
			Gen(pos + 1, len);
			if (!bValid) return;
		}
	} else {
		int i = pos;
		/* cout << "pos = " << pos << endl; */
		ll v = 0;
		while (i < len) { s[i++] = s[len - i - 1]; } 
		for (i = 0; i < len; i++) {
			v = v * 10 + s[i];
		}
		if (v < a ) return;
		if (v > b) { bValid = false; return; }
		if (isPrime(v))
			cout << v << endl;
	}
}

int main() {
	cin >> a >> b;
	for (int i = 0; i < 9; i++) 
		Gen(0, i+1);

}

