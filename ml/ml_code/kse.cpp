int N, K;
cin >> N >> K;
vector<ll> vw(N);
for(int i = 0; i < N; i++) cin >> vw[i];
vector<int> c(N);
for(int i = 0; i < N; i++){
	cin >> c[i];
	c[i]--;
}
if(c == vector<int>(N, -1)) c[0] = 0;
vector<vector<int> > tree(N);
for(int i = 0; i < N-1; i++){
	int u, v;
	cin >> u >> v;
	u--; v--;
	tree[u].push_back(v);
	tree[v].push_back(u);
}
vector<int> par(N);
vector<int> ord;
vector<int> idx(N);
y_combinator(
	[&](auto self, int v, int p) -> void {
		idx[v] = (int)ord.size();
		ord.push_back(v);
		par[v] = p;
		for(int w : tree[v]){
			if(w == p) continue;
			self(w, v);
		}
	}
)(0, -1);
ecnerwala::level_ancestor la(par);
vector<vector<int> > color_where(K);
for(int v = 0; v < N; v++){
	if(c[v] >= 0) color_where[c[v]].push_back(v);
}
vector<bool> bad(N);
ll twgt = 0;
for(int k = 0; k < K; k++){
	sort(color_where[k].begin(), color_where[k].end(), [&](int x, int y){
		return idx[x] < idx[y];
	});
	for(int i = 0; i + 1 < (int)color_where[k].size(); i++){
		int l = la.lca(color_where[k][i], color_where[k][i+1]);
		if(c[l] == -1){
			c[l] = k;
		}
		if(c[l] != k){
			bad[l] = 1;
		}
	}
}
for(int v = 0; v < N; v++) if(bad[v]) twgt += vw[v];
y_combinator(
	[&](auto self, int v, int p) -> void {
		for(int w : tree[v]){
			if(w == p) continue;
			self(w, v);
			if(c[v] == -1) c[v] = c[w];
		}
	}
)(0, -1);
y_combinator(
	[&](auto self, int v, int p) -> void {
		for(int w : tree[v]){
			if(w == p) continue;
			if(c[w] == -1) c[w] = c[v];
			self(w, v);
		}
	}
)(0, -1);
cout << twgt << '\n';
for(int i = 0; i < N; i++){
	cout << (c[i]+1) << " \n"[i+1 == N];
}
