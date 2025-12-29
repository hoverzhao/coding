auto nsums = [&](int N, int K) -> num {
	if(K == 0) return N == 0;
	return ncr(N+K-1, K-1);
};
auto cnt_ways = [&](int N, int M, int L){
	num val = 0;
	for(int a = 0; a*(L+1) <= M-L && a <= N-1; a++){
		val += ncr(N-1, a) * nsums(M-L - a*(L+1), N-1) * ((a & 1) ? -1 : 1);
	}
	// cerr << "cnt " << N << ' ' << M << ' ' << L << ' ' << val << '\n';
	return val;
};
auto solve_end = [&](int N, int M, int L) -> num {
	num ans = 0;
	ans += L * cnt_ways(N, M, L);
	num sum_a0 = 0;
	num sum_a0_bad = 0;
	num bad_ways = 0;
	for(int a = 0; a*(L+1) <= M-L && a <= N-2; a++){
		sum_a0 += ncr(N-2, a) * nsums(M-L-1 - a*(L+1), N) * ((a & 1) ? -1 : 1);
		sum_a0_bad += ncr(N-2, a) * nsums(M-L-1 - a*(L+1) - (L+1), N) * ((a & 1) ? -1 : 1);
		bad_ways += ncr(N-2, a) * nsums(M-L - a*(L+1) - (L+1), N-1) * ((a & 1) ? -1 : 1);
	}
	sum_a0_bad += (L+1) * bad_ways;
	ans -= (sum_a0 - sum_a0_bad);
	// cerr << "end " << N << ' ' << M << ' ' << L << ' ' << ans << ' ' << sum_a0 << ' ' << sum_a0_bad << '\n';
	return ans;
};
int N, M;
cin >> N >> M;
num ans = 0;
for(int L = 1; L <= M; L++){
	num cL = 0;
	cL += solve_end(N, M, L);
	cL += (N-2) * solve_end(N-1, M-L, L);
	// cerr << L << ' ' << cL << '\n';
	ans += cL;
}
cout << ans << '\n';
