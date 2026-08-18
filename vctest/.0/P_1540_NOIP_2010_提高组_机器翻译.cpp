#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	return 0;
}();

const int N = 10003;

struct st {
	int r, h;
	int d[N];
	int size() {return (r - h + N) % N;}
	bool empty() {return (size() == 0) ? true : false;}
	void push(int e) { if ((r+1) % N  == h) return; d[r] = e; r = (r+1) % N;}
	int front() {return d[h];}
	void pop() {if (r == h) return; h = (h+1) % N;}
}q;

int ash[N];
int main() {
	int m, n;
	cin >> m >> n;
	int ans = 0;
	while (n--) {
		int k; cin >> k;
		if (!ash[k]) {
			ash [k] = 1;
			ans++;
			if (q.size() >= m) {
				ash[q.front()] = 0;
				q.pop();
			}
			q.push(k);
		}
	}

	cout << ans;
	return 0;
}