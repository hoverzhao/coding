#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "*" << #x << " -> "; err(x); } while (0)
void err() {cout << endl; }
template<template<typename...> class T, typename t, typename...A>
void err(T<t> a, A... x) { for (auto v : a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif

static int x = []() {
	/* ios::sync_with_stdio(false); cin.tie(0); */
	freopen("baseio.in", "r", stdin);
	freopen("baseio.out", "w", stdout);
	return 0;
}();


using ll = long long;
using lld = long double;
int INF = 1e9;
long long LINF = 1e18;

int main() {
	/* This disables the synchronization between the C and C++ standard streams. By default, all standard streams are synchronized, */ 
	/*  which in practice allows you to mix C- and C++-style I/O and get sensible and expected results. If you disable the synchronization, */ 
	/*  then C++ streams are allowed to have their own independent buffers, which makes mixing C- and C++-style I/O an adventure. */
	/* ios_base::sync_with_stdio(false); */

	/* This unties cin from cout. Tied streams ensure that one stream is flushed automatically before each I/O operation on the other stream. */
	/* By default cin is tied to cout to ensure a sensible user interaction. For example: */
	/* cin.tie(NULL); */
	/* cout << "Enter name:"; */
	/* cin >> name; */

	/* If cin and cout are tied, you can expect the output to be flushed (i.e., visible on the console) before the program prompts input from the user. If you */ 
	/* untie the streams, the program might block waiting for the user to enter their name but the "Enter name" message is not yet visible (because cout is */ 
	/* buffered by default, output is flushed/displayed on the console only on demand or when the buffer is full). */

	/* Manages the tied stream. A tied stream is an output stream which is synchronized with the sequence controlled by the stream buffer (rdbuf()), */ 
	/* 		that is, flush() is called on the tied stream before any input/output operation on *this. */
	/* In C++, By default, the standard input device is tied together with the standard output device in the form: cin.tie (&cout); */
	/* which guarantees that the output buffer has been flushed before input is invoked. */
	ofstream os("test.in");
    ifstream is("test.in");
    string value("0");
 
    os << "Hello";
    is >> value;
    cout << "Result before tie(): \"" << value << "\"\n";

    is.clear();
    is.tie(&os);
    is >> value;
    cout << "Result after tie(): \"" << value << "\"\n";

	cout << endl << endl;

	/* Output: */
	/* Result before tie(): "0" */
	/* Result after tie(): "Hello" */


	/* Returns the number of characters extracted by the last unformatted input operation, gcount() */ 
    char x[20];
    istringstream stream("Hello World");
    stream.read(x, sizeof x);
    cout << "Characters extracted: " << stream.gcount();
	cout << endl << endl;
	// output:
	/* Characters extracted: 11 */

	ifstream file("baseio.in");
    if(!file)  // operator! is used here
    {  
        cout << "File opening failed\n";
        return EXIT_FAILURE;
    }
    // typical C++ I/O loop uses the return value of the I/O function
    // as the loop controlling condition, operator bool() is used here
    for(int n; file >> n; ) {
       cout << n << ' ';
    }
    cout << '\n';
 
    if (file.bad())
        cout << "I/O error while reading\n";
    else if (file.eof())
        cout << "End of file reached successfully\n";
    else if (file.fail())
        cout << "Non-integer data encountered\n";
	cout << endl << endl;

	/* basic_istream& ignore( streamsize count = 1, int_type delim = Traits::eof() ); */
	/* count characters were extracted. This test is disabled in the special case when count equals numeric_limits<streamsize>::max() */
	/* Extracts and discards characters from the input stream until and including delim. */
	istringstream input("1\n" "some non-numeric input\n" "2\n");
    for(;;) {
        int n;
        input >> n;
 
        if (input.eof() || input.bad()) {
            break;
        } else if (input.fail()) {
            input.clear(); // unset failbit
            input.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input
			cout << "xxx" << endl;
        } else {
            cout << n << '\n';
        }
    }
	cout << endl << endl;
	//	Output:
	//	1
	//	xxx
	//	2
	
    istringstream s1("Hello, world.");
    char c1 = s1.get(); // reads 'H'
    cout << "after reading " << c1 << ", gcount() == " <<  s1.gcount() << '\n';
    char c2;
    s1.get(c2);         // reads 'e'
    char str[5];
    s1.get(str, 5);     // reads "llo,"
    cout << "after reading " << str << ", gcount() == " <<  s1.gcount() << '\n';
    cout << c1 << c2 << str;
    s1.get(*cout.rdbuf()); // reads the rest, not including '\n'
    cout << "\nAfter the last get(), gcount() == " << s1.gcount() << '\n';

	// 情况一：输入一组整数，不知多少个，回车结束输入
	// int s[10001];
	int i = 0;
	while(cin >> s[i]){
		i++;
		if(cin.get() == '\n'){
			break;
		}
	}
	int n;
	cin >> n;
	// error cin 和getline 间要加ignore 吃掉 行尾\n
	cin.ignore();
	/* cin.ignore(); */

	vector<vector<string>> s;
	string tmp = {}; string t2 = {};
	while (n--) {
		getline(cin, tmp); 
		//error 大坑 洛谷数据文件使用windows \n\r 换行，而linux使用\n换行
		if (tmp[tmp.size() - 1] == '\r') tmp.erase(tmp.size() - 1); 
		istringstream input(tmp);
		vector<string> v;
		while (getline(input, t2,' ')) {
			v.push_back(t2);
		}
		s.push_back(v);
	}

	return 0;
}

