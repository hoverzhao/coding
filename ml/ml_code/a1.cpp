std::vector<int> a(n);
for (int i = 0; i < n; i++) {
	std::cin >> a[i];
	a[i]--;
}
std::vector<int> cnt(n), p(n);
for (int i = 0; i < n; i++) {
	cnt[a[i]]++;
}
for (int i = 1; i < n; i++) {
	cnt[i] += cnt[i - 1];
}
for (int i = 0; i < n; i++) {
	p[--cnt[a[i]] = i;
}

