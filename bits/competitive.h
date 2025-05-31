#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

//const int INF = 1e9 + 7;
//const ll LINF = 1e18 + 7;
//const double EPS = 1e-9;

typedef vector<int> vi;
typedef vector<ll> vl;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

typedef vector<pii> vpii;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

#define endl '\n'
#define debug(...) fprintf(stderr, __VA_ARGS__)

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}


