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

const int maxlen = 200;

class lln { 
	public:
		lln(string s) { 
			a.clear(); 
			size_t len = s.size(); 
			int i = 0; 
			while (--len) { a.push_back(s[i] - '0'); } 
		}

		lln(const lln& b) { a = b.a; } // lln n(n0);   lln n = n0;

		lln& operator= (const lln& b) {		// n = n0;
			if (this == &b)
				return *this;
			a.clear();
			a = b.a;
		}

		size_t size() { return a.size();}

		friend lln operator+ (const lln& lv, const lln& rv) {
			vector<int> ans(maxlen, 0);

			size_t n = max(lv.size(), rv.size());
			for (size_t i = 0; i < n; i++) {
				ans[i + 1] = (lv[i] + rv[i]) / 10;
				ans[i] = (lv[i] + rv[i]) % 10;
			}
			while (ans[n] == 0 && n > 0) n--;
			return ans.erase(n, ans.end());
		}

		friend lln operator- (const lln& lv, const lln& rv) {

		}

		friend lln operator* (const lln& lv, const lln& rv) {

		}

		friend ostream& operator<< (ostream& out, const lln& v) {

		}

	private:
		vector<int> a;
		vector<int> ans;
};




int main() {
	int n;
	cin >> n;
	
	return 0;
}

