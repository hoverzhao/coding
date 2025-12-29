bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}
 
vector<int> test_P;
int N;
if(TEST_N){
	N = TEST_N;
	mt19937 mt_test(48);
	for(int i = 0; i < N; i++) test_P.push_back(i);
	while(true){
		shuffle(test_P.begin(), test_P.end(), mt_test);
		bool ok = true;
		for(int i = 0; i < N; i++){
			if(test_P[i] == i) ok = false;
		}
		if(ok) break;
	}
} else {
	cin >> N;
}
int K = N/2;
cout << (K+1) << '\n';
auto ask = [&](vector<int> q) -> int {
	int val;
	if(TEST){
		val = 0;
		for(int i = 0; i < N; i++){
			if(i == K) continue;
			for(int j = i+1; j < N; j++){
				if(test_P[q[i]] == q[j]) val++;
			}
		}
	} else {
		cout << "?";
		for(int a : q){
			cout << ' ' << (a+1);
		}
		cout << '\n';
		cout << flush;	
		cin >> val;	
	}
	return val;
};
mt19937 mt(48);
int best_tsame = 1e9;
vector<vector<int> > best_mask, best_perms;

int B = 15;
auto gen = [&](){
	vector<vector<int>> mask(N, vector<int>(N));

	vector<vector<int> > perms;
	vector<int> perm(N);
	for(int it = 0; it < B; it++){
		for(int i = 0; i < N; i++) perm[i] = i;
		shuffle(perm.begin(), perm.end(), mt);
		perms.push_back(perm);
		for(int j = 0; j < N; j++){
			for(int l = 1; l <= K; l++){
				int k = (j+l + N) % N;
				mask[perm[j]][perm[k]] |= 1 << it;
			}
		}
	}
	int tsame = 0;
	for(int j = 0; j < N; j++){
		vector<int> d;
		for(int a = 0; a < N; a++){
			if(a == j) continue;
			d.push_back(mask[j][a]);
		}
		sort(d.begin(), d.end());
		int nsame = 0;
		for(int i = 0; i+1 < (int)d.size(); i++){
			if(d[i] == d[i+1]) nsame++;
		}
		tsame += nsame;
	}
	if(tsame < best_tsame){
		best_tsame = tsame;
		best_mask = mask;
		best_perms = perms;
	}
};
for(int it = 0; it < 100; it++){
	if(best_tsame == 0) break;
	gen();
}
// cerr << N << ": " << best_tsame << '\n';
vector<vector<int> > ok(N, vector<int>(N, 1));
for(int i = 0; i < N; i++) ok[i][i] = 0;
auto perms = best_perms;
vector<vector<int> > answers(B);
vector<int> known(N, -1);
for(int id = 0; id < B; id++){
	answers[id].resize(N);
	for(int cyc = 0; cyc < N; cyc++){
		vector<int> perm = perms[id];
		rotate(perm.begin(), perm.begin() + cyc, perm.end());
		vector<int> z = perm;
		z.insert(z.begin() + K, z.back());
		z.pop_back();
		answers[id][cyc] = ask(z);
	}
}
for(int rr = 0; rr < 2; rr++){
	for(int id = 0; id < B; id++){
		int amin = *min_element(answers[id].begin(), answers[id].end());
		int amax = *max_element(answers[id].begin(), answers[id].end());
		if(amin == amax){
			int amin_wrong = 0;
			int amax_wrong = 0;
			for(int cyc = 0; cyc < N; cyc++){
				vector<int> perm = perms[id];
				rotate(perm.begin(), perm.begin() + cyc, perm.end());
				for(int l = 0; l < N-1; l++){
					if(known[perm[l]] == perm.back()){
						if(!((l < K) == (answers[id][cyc] != amin))){
							amin_wrong = 1;
						} else {
							amax_wrong = 1;
						}
					}
				}
			}
			assert(!(amin_wrong && amax_wrong));
			if(amin_wrong) amin--;
			if(amax_wrong) amax++;
		}
		if(amin != amax){
			for(int cyc = 0; cyc < N; cyc++){
				vector<int> perm = perms[id];
				rotate(perm.begin(), perm.begin() + cyc, perm.end());
				for(int l = 0; l < N-1; l++){
					ok[perm[l]][perm.back()] &= (l < K) == (answers[id][cyc] != amin);
				}
			}
		}
	}
	for(int i = 0; i < N; i++){
		vector<int> vok;
		for(int j = 0; j < N; j++){
			if(ok[i][j]) vok.push_back(j);
		}
		if(vok.size() == 1) known[i] = vok.front();
	}
}
vector<vector<int> > G(N);
for(int i = 0; i < N; i++){
	for(int j = 0; j < N; j++){
		if(ok[i][j]) G[i].push_back(j);
	}
}
vector<int> btoa(N, -1);
dfsMatching(G, btoa);
for(int i = 0; i < N; i++) known[btoa[i]] = i;
if(TEST){
	for(int i = 0; i < N; i++){
		assert(ok[i][test_P[i]]);
	}
	assert(known == test_P);
}
cout << "!";
for(int i = 0; i < N; i++){
	cout << " " << (known[i] + 1);
}
cout << '\n';
cout << flush;
