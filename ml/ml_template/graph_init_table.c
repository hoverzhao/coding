#include <stdio.h>
#include <string.h>

#define VN 30
#define EN 30
#define INF 0x3f3f3f3f

int book[VN] = {0}, dis[VN] = {INF};  //error
int h[VN], pos[VN], size;

void shiftup(int i);
void shiftdown(int i);
int	 pop();
void swap(int i, int j);

void swap(int i, int j) {
	int a = h[i];
	h[i] = h[j];
	h[j] = a;
	
	int b = pos[h[i]];
	pos[h[i]] = pos[h[j]];
	pos[h[j]] = b;
}

void shiftup(int i) {
	int flag = 0;
	if ( i == 1) return;
	while (i != 1 && flag == 0) {
		if ( dis[h[i]] < dis[h[i/2]]) { // error
			swap(i, i/2);
		} else {
			flag = 1;
		}
		i /= 2;
	}
}

void shiftdown(int i) {
	int flag = 0;
	int t = 0;
	while (i * 2 <= size && flag == 0) {

		if (dis[h[i]] > dis[h[i * 2]])
			t = i * 2;
		else
			t = i;

		if (i * 2 + 1 <= size && dis[h[t]] > dis[h[i * 2 + 1]]) // error
			t = i * 2 + 1;

		if (t != i)
			swap(t, i);
		else
			flag = 1;
		i = t;
	}
}

int pop() {
	int t = h[1];
	swap(1, size--);
	shiftdown(1);
	return t;
}

int main() {
	int n = 0, m = 0, i = 0, j = 0, k = 0;
	int u[EN], v[EN], w[EN], first[VN], next[EN];
	int sum = 0, count = 0;

	//Graph初始化
	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}

	for (i = m + 1; i <= 2 * m; i++){
		u[i] = v[i - m];
		v[i] = u[i - m];
		w[i] = w[i - m];
	}

	memset(first, -1, sizeof(int) * VN); 
	/* for (i = 1; i <= n; i++) first[i] = -1; */
	for (j = 1; j <= 2*m; j++) {
		next[j] = first[u[j]];
		first[u[j]] = j;
	}

	// 全局变量初始化
	book[1] = 1; count++;

	// 初始化Dis数组
	dis[1] = 0;
	for (i = 2; i <= n; i++) dis[i] = INF; // error
	k = first[1];
	while (k != -1) {
		dis[v[k]] = w[k];
		k = next[k];
	}

	//堆初始化
	size = n;
	for (i = 1; i <= size; i++) { h[i] = i; pos[i] = i;}
	for (i = size / 2; i >= 1; --i) { shiftdown(i); }

	pop();

	while (count < n) {
		j = pop();
		book[j] = 1; count++; sum = sum + dis[j];
		k = first[j];
		while (k != -1)  {
			if (book[v[k]] == 0 && dis[v[k]] > w[k]) {
				dis[v[k]] = w[k];
				shiftup(pos[v[k]]);
			}
			k = next[k];
		}
	}


	printf("sum = %d \n", sum);
	getchar(); getchar();
	return 0;
}

while (count < n) {
	j = pop();
	book[j] = 1; count++; sum = sum + dis[j];
	k = first[j];
	while (k != -1)  {
		if (book[v[k]] == 0 && dis[v[k]] > w[k]) {
			dis[v[k]] = w[k];
			shiftup(pos[v[k]]);
		}
		k = next[k];
	}
}
