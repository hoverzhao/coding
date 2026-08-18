#include <bits/stdc++.h>
using namespace std;

static int x = []() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}();

const int n = 1000100;
deque<int> q;
int s[2*n];

int main() {
	int n, ans; cin >> n; ans = 0;
	for(int i = 1; i <= n; i++) {cin >> s[i]; s[i+n] = s[i];}
	for(int i = 1; i <= 2*n; i++) s[i] += s[i-1];
	for(int i = 1; i < 2*n; i++){
		while(!q.empty() && s[q.back()] > s[i]) q.pop_back();
		q.push_back(i);
		if(i >= n){
			while(!q.empty() && q.front() <= i-n) q.pop_front();
			if (s[q.front()] - s[i-n] >= 0){
				ans++;
			}
		}
	}

	cout << ans <<endl;
	return 0;
}