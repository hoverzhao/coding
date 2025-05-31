#include <bits/stdc++.h>
#include <random>
#include <chrono>
// 参考使用 https://github.com/MikeMirzayanov/testlib

using namespace std;
typedef long long ll;

//不要使用srand(time(NULL))生成随机种子 , 因为time只精确到秒，所以如果在同一秒内
//多次调用srand(time(NULL))，会得到相同的随机数序列。
//如果黑客能猜到你程序的运行秒数，就可以预测你的随机数序列。完成复现破解攻击

//要使用mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count())来获取更精确的时间戳后
//生成的随机种子 或 使用default_random_engine rng; 来生成随机种子

// 不要使用rand() ，和 random_suffle()生成随机数, 因为它们随机最大值是RAND_MAX = 32767 

//要使用函数suffle(),mt19937为参数, 替换 random_suffle()
//最好使用 <random> 头文件中的随机数生成器和分布函数来生成随机数。

/*
	#include <random>
	#include <chrono>

	mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
	
	uniform_int_distribution<long long>(L, R)(rng);    范围是[L, R]，包括L和R
	uniform_real_distribution<> dis(1.0, 2.0);    // 范围是[1.0, 2.0)，不包括2.0;
*/

/* // 生成一个长度为N的随机排列，并计算其平均距离
	const int N = 3000000;

	double average_distance(const vector<int> &v) {
		double distance_sum = 0;

		for (int i = 0; i < N; i++)
			distance_sum += abs(v[i] - i);

		return distance_sum / N;
	}

	int main() {
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		vector<int> v(N);

		for (int i = 0; i < N; i++)
			v[i] = i;

		shuffle(v.begin(), v.end(), rng);
		cout << average_distance(v) << '\n';

		for (int i = 0; i < N; i++)
			v[i] = i;

		for (int i = 1; i < N; i++)
			swap(v[i], v[uniform_int_distribution<int>(0, i)(rng)]);

		cout << average_distance(v) << '\n';
	}
*/

//传统方法 （有缺陷)
// srand(time(NULL));
// 通用公式: rand() % n + a；其中的 a 是起始值，n 是整数的范围。
// [a,b)  (rand() % (b-a))+ a;
// [a,b]  (rand() % (b-a+1))+ a;
// (a,b]  (rand() % (b-a))+ a + 1;
//要取得 a 到 b 之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
//要取得 0～1 之间的浮点数，可以使用 rand() / double(RAND_MAX)。

mt19937 	rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

int rand_Int(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

double rand_Double(double l, double r) {
	return uniform_real_distribution<double>(l, r)(rng);
}


int main() {

	int a, b, n;
	a = rand_Int(1, 5); // [1 5]
	n = 10;

	//生成树 编号1-n
	for(long i = 2; i <= n; ++i) 
		cout << (rand_Int(1, n)) << " " << i << "\n";
	return 0;
}

