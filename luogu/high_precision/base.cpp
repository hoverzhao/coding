
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

/* for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0'); */
void out(const vector<int> &A) {
    for (int i = (int)A.size() - 1; i >= 0; i--) {
        cout << A[i];
    }
}
// A < B, A > 0, B > 0
bool cmp(vector<int> &A, vector<int> &B) {
    if ((int)A.size() != (int)B.size()) {
        return (int)A.size() < (int)B.size();
    }
    for (int i = (int)A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) return A[i] < B[i];
    }
    return false;
}
// O(n)
// C = A + B, A >= 0, B >= 0
vector<int> add(const vector<int> &A, const vector<int> &B) {
    if ((int)A.size() < (int)B.size()) return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        t += A[i];
        if (i < (int)B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}
// O(n)
// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(const vector<int> &A, const vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < (int)A.size(); i++) {
		//如果借过位，需要减去t(t是借位数量)
        t = A[i] - t;
        if (i < (int)B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
		// 小于零 表明发生借位
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
// O(n)
// C = A * b, A >= 0, b > 0
vector<int> mul(const vector<int> &A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < (int)A.size() || t; i++) {
        if (i < (int)A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t = t / 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
// O(nm)
// C = A * B, A >= 0, B >= 0
vector<int> mul_high(const vector<int> &A, const vector<int> &B) {
    vector<int> C((int)A.size() + (int)B.size());
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }
    int t = 0;
    for (int i = 0; i < (int)C.size(); i++) {
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// O(n)
// A / b = C ... r, A >= 0, b > 0
vector<int> div(const vector<int>& A, int b, int& r) {
    vector<int> C;
    r = 0;
    for (int i = (int)A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r = r % b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// O((n-m)*n)
pair<vector<int>, vector<int>> div_high(vector<int> A, const vector<int> &B) {
    vector<int> C, R;
    int n = (int)A.size(), m = (int)B.size(), d = n - m;
    C.resize(d + 1, 0);
    // 枚举补0的个数 
    for (int len = d; len >= 0; len--) {
        vector<int> Bp(len, 0);
        for (int x : B) Bp.push_back(x);

        // A >= Bp
        while (!cmp(A, Bp)) {
            C[len] += 1;
            A = sub(A, Bp);
        }
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    R = A;
    return make_pair(C, R);
}

int main() {

	return 0;
}

