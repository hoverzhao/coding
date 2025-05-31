Synthesized 8 completions
Press <CR> on a completion to accept
────────────────────────────────────────────────────────────────────────
}();

// Function to calculate the sum of two integers
────────────────────────────────────────────────────────────────────────
}();

// If you want to use a random number generator, you can uncomment the following line:
// #define RANDOM_GENERATOR

#ifdef RANDOM_GENERATOR
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rnd);
}
#endif
────────────────────────────────────────────────────────────────────────
}();

// Fast IO
void fast_io() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

// Debugging macros
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl

// Constants
const int INF = 1e9 + 10;
const ll LINF = 1e18 + 10;
const double EPS = 1e-9;

// Main function
────────────────────────────────────────────────────────────────────────
}();

// For local testing, comment the above lines and uncomment below
// #define LOCAL

#ifdef LOCAL
#define FILEIO
#endif

#ifdef FILEIO
#define freopen(a, b, c) (void)0 // Disable file IO for local testing
#endif
────────────────────────────────────────────────────────────────────────
}();

// Function to read integers
inline int readInt() {
	int x;
	cin >> x;
	return x;
}

// Function to read strings
inline string readString() {
	string s;
	cin >> s;
	return s;
}

// Function to write output
inline void writeOutput(const string &s) {
	cout << s << endl;
}

// Main function
────────────────────────────────────────────────────────────────────────
}();

// Problem: A + B
// Contest: Codeforces - Codeforces Round #188 (Div. 2)
// URL: https://codeforces.com/problemset/problem/304/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// You are given two integers a and b. Output their sum.
────────────────────────────────────────────────────────────────────────
}();

// For testing purposes, remove the above lines in production
// #define freopen(a, b, c)
────────────────────────────────────────────────────────────────────────
}();

// Uncomment the following lines for debugging
// #define DEBUG
// #ifdef DEBUG
// #define debug(...) fprintf(stderr, __VA_ARGS__)
// #else
// #define debug(...)
// #endif
