#include <iostream>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	return 0;
}();

const int Inf = 1e5;

void solve(){
  		int n;
  		cin >> n;
  		int start = 1, end = 1, p = 1, sum = 0;
  		int maxsum = -Inf;
  		for (int i = 1; i <= n; i++) {
    		int a; cin >> a;
    		sum += a;
    		if (maxsum < sum) {
      		start = p, end = i, maxsum = sum;
    		}
    		if (sum < 0) {
      		p = i + 1, sum = 0;
    		}
		}
        cout << maxsum << ' ' << start << ' ' << end << '\n';
}

int main(){
	int t; cin >> t;
	int k = 1;
	while (t--){
		cout << "Case " << k++ << ':' <<'\n';
		solve();
		cout << endl;
	}
	return 0;
}