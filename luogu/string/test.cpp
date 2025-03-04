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

int main() {
	string a;
    string b;
    string c;
    string test;
    //cin可以连续从键盘读取想要的数据，以空格、tab或换行作为分隔符。
    /* cin >> a>>b>>c; */
    /* cout << a << " " << b << " " << c << endl; */


    /* getline(cin, test); */
    /* cout << test << endl; */
    //cin >> 对缓冲区中的第一个换行符/空格/tab视而不见，采取的措施是忽略清除，继续阻塞等待缓冲区有效数据的到来。
    //  但是，getline()读取数据时，并非像cin >> 那样忽略第一个换行符，
    //  getline()发现cin的缓冲区中有一个残留的换行符，不阻塞请求键盘输入，直接读取，送入目标字符串后，
    //  再将换行符替换为空字符’\0’，因此程序中的test为空串。

    /* char aa; */
    /* char bb; */
	/* char cc; */
    /* aa = cin.get();//输入A+空格 */
    /* cin.get(bb); */
	/* cin.get(cc); */
    /* cout << aa << bb << cc << endl; */

    //cin.get()从输入缓冲区读取单个字符时不忽略分隔符，直接将其读取，就出现了如上情况，将换行符读入变量b
    //cin.get(array, 20);读取一行时，只能将字符串读入C风格的字符串中，即char*，遇到换行符时结束读取，
    //但是不对换行符进行处理，换行符仍然残留在输入缓冲区。

    char s[10] = {};
    cin.getline(s,10);
    cin >> a;
    cout << s <<" "<<a<< endl;

    //cin.getline不会将结束符或者换行符残留在输入缓冲区中,cin.getline(字符指针(char*),字符个数N(int),结束符(char));
    //cin.getline 和getline是两个函数,cin.getline()属于istream流，而getline()属于string流

    //getline(cin, a);
    //cin >> b;
    //cout << a << " " << b << endl;
    //getline不会将结束符或者换行符残留在输入缓冲区中

    /* cin >> b; */
    /* cin.ignore(); */
    /* getline(cin, a); */
    /* cout << a << " " << b << endl; */
    //cin.ignore清空了输入缓冲区的当前行，使上次的输入残留下的数据没有影响到下一次的输入
	return 0;
}

