#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "*" << #x << " -> "; err(x); } while (0)
void err() {cout << endl; }
template<template<typename...> class T, typename t, typename...A>
void err(T<t> a, A... x) { for (auto v : a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();

/* #define LINF 0x3f3f3f3f3f3f3f3f */
#define INF  0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef long double ld;

const int maxlen = 1000;


vector<int> ans(maxlen, 0);
vector<int> seq;

void multi(int n) {
	for (int i = 0; i < maxlen; i++) {
		ans[i] = ans[i] * n;
	}
	for (int i = 0; i < maxlen - 1; i++) {
		ans[i + 1] += ans[i] / 10;
		ans[i] = ans [i] % 10;
	}
	/* dbg(ans); */
}

int main() {
	int n = 0;
	cin >> n;
	ans[0] = 1;
	int sum = 0; int i = 2;
	do {
		sum += i;
		seq.push_back(i);
		i++; 
		
	} while (sum < n);

	int a = sum - n;
	if ( a == 1 ) {
		seq.erase(seq.begin());
		seq[seq.size() -1]++;
	}
	else if (a != 0){
		seq.erase(seq.begin() + a - 2);
	}

	for (auto v : seq) {
		cout << v << ' ';
		multi(v);
	}
	cout << '\n';
	// 去除前导0; w<F10><F1
	int t = maxlen - 1;
	while (ans[t] == 0 && t != 0) t--;
	while (t >= 0) cout << ans[t--];
	

	return 0;
}

