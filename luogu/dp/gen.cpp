#include <bits/stdc++.h>
using namespace std;

#define ll long long

int mkrand(int nstart, int nend, int ncount = 1, bool oneline = false) {
	int n ;
	for (int i = 0; i < ncount; i++) {
		n = rand() % (nend - nstart + 1) + nstart;
		if (i == ncount - 1)
			printf("%d", n);
		else
			printf("%d ", n); 
	}
	if (!oneline)
		printf("\n");

	return n;
}

void mkrand_line() {

	int k = rand() % 2 + 2; 
	if (k == 3) 
		printf("%c ", rand() % 3 + 'a');
	
	mkrand(0, 9999, 2, true);
	printf("\n");
}

int main(){
	freopen("./t.in", "w", stdout);
	srand(time(0));
	int n =mkrand(3, 5);
	mkrand(0, 5, n);
	/* int n = mkrand(1, 4, 1); */
	/* for (int i = 0; i < n; i++) { */
	/* 	mkrand_line(); */
	/* } */

	/* mkrand(0, 100, 3); */
	/* mkrand(100, 120); */
	return 0;
}
