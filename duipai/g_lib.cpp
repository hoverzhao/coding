#include "testlib/testlib.h"
using namespace std;

/*
 * rnd.next(4)	An equiprobable random integer from 0 to 3 (inclusive)
rnd.next(4, 100)	An equiprobable random integer from 4 to 100 (inclusive)
rnd.next(10.0)	An equiprobable random real number in the half-interval [0;10)
rnd.next("one|two|three")	An equiprobable random word out of 'one', 'two' and 'three'
rnd.next("[1-9][0-9]{99}")	An equiprobable random 100-digit number as a string

rnd.wnext(4,t)	wnext is a method of obtaining an uneven distribution (with a biased expectation), the parameter t denotes the number of calls to the maximum operation for similar next calls. For example rnd.wnext(3, 1) is equivalent to max(rnd.next(3), rnd.next(3)), and rnd.wnext(4, 2) is equivalent to max(rnd.next(4), max(rnd.next(4), rnd.next(4))). If t < 0, then -t will find the minimum. If t = 0, then wnext is equivalent to next.

rnd.any(container)	A random element of the container container (with random access via an iterator), for example, it works for std::vector and std::string

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    cout << rnd.next(1) << " ";
    cout << rnd.next(2, 3) << endl;
	cout << rnd.next("[8-9][8-9][0-6]{5}") << endl; // 返回一个从字母 a 到 z 的随机长度为 1 到 10 的单词
    cout << rnd.next("one|two|three") << endl;
	cout << rnd.wnext(4, 9) << endl;
	vector<int> v = {55,33,44};
	cout << rnd.any(v) << endl;
}
*/

/*Example: generating an undirected tree
示例：生成无向树
*/
int main(int argc, char* argv[]) {
	/*
Below is the code of an undirected tree generator that takes two parameters — the number of vertices and the 'elongation' of the tree. For example:
下面是一个无向树生成器的代码，它接受两个参数——顶点数和树的“伸长率”。例如：
For n = 10, t = 1000, a path graph (degree of all vertices are at most 2) is likely to be generated
当 n = 10，t = 1000 时，可能会生成路径图（所有顶点的度数最多为 2 个
For n = 10, t =  - 1000, a star graph (there's only one non-leaf vertex in the tree) is likely to be generated 对于 n = 10，t = - 1000，可能会生成星图（树中只有一个非叶顶点）。
*/
	registerGen(argc, argv, 1);

	int n = atoi(argv[1]);
	int t = atoi(argv[2]);

	vector<int> p(n);

	/* setup parents for vertices 1..n-1 */
	for(int i = 0; i < n; ++i)
		if (i > 0)
			p[i] = rnd.wnext(i, t);

	printf("%d\n", n);

	/* shuffle vertices 1..n-1 */
	vector<int> perm(n);
	for(int i = 0; i < n; ++i)
		perm[i] = i;
	shuffle(perm.begin() + 1, perm.end());

	/* put edges considering shuffled vertices */
	vector<pair<int,int> > edges;
	for (int i = 1; i < n; i++)
		if (rnd.next(2))
			edges.push_back(make_pair(perm[i], perm[p[i]]));
		else
			edges.push_back(make_pair(perm[p[i]], perm[i]));

	/* shuffle edges */
	shuffle(edges.begin(), edges.end());

	for (int i = 0; i + 1 < n; i++)
		printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
	return 0;
}
/*
How to write a multiple-test generator?
A multiple-test generator in one execution can output more than one test. Tests by such a generator are output to files. In the generator on testlib.h it is enough to write startTest(test_index) before the test output. This will re-open (freopen) the standard output stream to a file named test_index.

Please note that if you are working with the Polygon system, in this case, you need to write something like multigen a b c > {4-10} in the script (if it is assumed that starting the multiple-test generator will return tests 4, 5, 6, 7, 8, 9, and 10).

Other notes about generators
Strictly follow the format of the test — spaces and line breaks should be placed correctly. The test should end with a line feed. For example, if the test consists of a single number, then output it as cout << rnd.next (1, n) << endl; — with a line feed at the end.
If the test size is large, it is prefered to use printf instead of cout — this will improve the performance of the generator.
It is better to use cout to output long long, but if you want printf, then use the I64 constant (for example, printf(I64, x);).
Please be aware about various cases of C++ undefined behavior. For example, in the first example generator above, if the two cout commands are combined into one, the order of the rnd.next function calls is not defined.
Translator's note: about the third point, using lld constant with printf to output long long used to be problematic in the past, but is no longer an issue now.*/
