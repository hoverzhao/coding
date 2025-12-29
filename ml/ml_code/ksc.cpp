int N, K;
cin >> N >> K;
vector<ll> A(N), B(N);
for(int i = 0; i < N; i++){
	cin >> A[i];
}
for(int i = 0; i < N; i++){
	cin >> B[i];
}
ll ans = 0;
ll best = 1e18;
vector<pair<ll, ll> > p;
for(int i = 0; i < N; i++){
	if(A[i] > B[i]) swap(A[i], B[i]);
	ans += B[i] - A[i];
	p.push_back({A[i], B[i]});
}
sort(p.begin(), p.end());
for(int i = 0; i+1 < (int)p.size(); i++){
	if(p[i].second >= p[i+1].first){
		best = 0;
	} else {
		best = min(best, 2 * (p[i+1].first - p[i].second));
	}
}
cout << (ans+best) << '\n';
