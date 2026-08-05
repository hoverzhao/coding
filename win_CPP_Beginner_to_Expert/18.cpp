/**
 * Author:    Tridib Samanta
 * Created:   15.01.2020
 **/

#include<iostream>
using namespace std;

//While overloading functions the function name will be the same.
//Function return type and function parameters will be different.

template <typename T, typename D>
T power(T b,D e) {
    T tmp=b;
    while(e>1) {
        b = b*tmp;
        e--;
    }
    return b;
}

int main() {
    cout<<power<float, int>(2.8, 3)<<endl;
    cout<<power<int, int>(2, 3)<<endl;
    system("pause");
    return 0;
}


