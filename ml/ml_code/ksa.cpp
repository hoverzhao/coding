int N;
cin >> N;
vector<int> A(N);
for(int i = 0; i < N; i++) cin >> A[i];
map<int,int> v;
for(int x : A) if(x >= 0) v[x] = 1;
if(v.size() > 1 || v[0]){
	cout << "NO" << '\n';
} else {
	cout << "YES" << '\n';
}
