int N;
cin >> N;
int M;
cin >> M;
vector<vector<int> > tree(N);
for(int i = 0; i < M; i++){
	int u, v;
	cin >> u >> v;
	u--; v--;
	tree[u].push_back(v);
	tree[v].push_back(u);
}
if(M >= N){
	cout << 0 << '\n';
	return;
}
if(N == 2){
	cout << 2 << '\n';
	return;
}
vector<int> leaf_deg(N);
vector<int> nonleaf_deg(N);

int nonleaf = 0;
for(int i = 0; i < N; i++){
	if(tree[i].size() == 1){
		for(int j : tree[i]){
			leaf_deg[j] += 1;
		}
	} else {
		nonleaf++;
		for(int j : tree[i]){
			nonleaf_deg[j] += 1;
		}
	}
}
for(int i = 0; i < N; i++){
	if(nonleaf_deg[i] >= 3){
		cout << 0 << '\n';
		return;
	}
}
num ans = 1;
ans *= 2;
for(int x : leaf_deg) ans *= fact[x];
if(nonleaf >= 2) ans *= 2;
cout << ans << '\n';
