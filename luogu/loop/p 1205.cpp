#include <bits/stdc++.h>

#define ll	long long
#define INF 0x3f3f3f3f
#define eb emplace_back
#define mp make_pair

using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();

char s[10][10] = {};
char d[10][10] = {};
char c[10][10] = {};
int ans[7] = {};
int i = 0, j = 0;
int n = 0;

bool rotate90() {
	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			if (d[i][j] != s[n - 1 - j][i]) 
				return false;
	return true;
}

bool rotate180() {
	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			if (d[i][j] != s[n - 1 - i][n - 1 - j])
				return false;
	return true;
}

bool rotate270() {
	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			if (d[i][j] != s[j][n - 1 - i]) 
				return false;
	return true;
}

bool smirror() {
	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			if (d[i][j] != s[i][n - 1 - j]) 
				return false;
	return true;
}

bool scompose() {
	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			c[i][j] = s[i][n - 1 - j]; 

	bool bt[3] = {true, true, true};
	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			if (d[i][j] != c[n - 1 - j][i]) 
				bt[0] = false;

	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			if (d[i][j] != c[n - 1 - i][n - 1 - j])
				bt[1] = false;

	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			if (d[i][j] != c[j][n - 1 - i]) 
				bt[2] = false;

	return bt[0] || bt[1] || bt[2];
}

bool unchanged() {
	for (i = 0; i < n; i++) 
		for(j = 0; j < n; j++) 
			if (d[i][j] != s[i][j]) 
				return false;
	return true;
}


int main() {
	cin >> n;
	for (i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			cin >> s[i][j];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> d[i][j];

	if (rotate90())		{cout << 1; return 0;}
	if (rotate180())	{cout << 2; return 0;}
	if (rotate270())	{cout << 3; return 0;}
	if (smirror())		{cout << 4; return 0;}
	if (scompose())		{cout << 5; return 0;}
	if (unchanged())	{cout << 6; return 0;}
	cout << 7;
	return 0;
}

