#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	return 0;
}();

int a[1000100];
deque<int> q;
int main() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		while(!q.empty() && a[q.back()] > a[i]) q.pop_back();
		q.push_back(i);
		if(i>=k){
			while(!q.empty() && q.front() <= i-k) q.pop_front();
			cout << a[q.front()] << ' ';
		}
	}
	q.clear();
	cout << endl;
	for (int i = 1; i <= n; i++) {
		while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
		q.push_back(i);
		if(i>=k){
			while(!q.empty() && q.front() <= i-k) q.pop_front();
			cout << a[q.front()] << ' ';
		}
	}
	return 0;
}
