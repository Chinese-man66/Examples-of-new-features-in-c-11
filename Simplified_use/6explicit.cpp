#include<iostream>
using namespace std;

//explicit专用于修饰构造函数，表示只能显式构造，不可以被隐式转换
struct A {
    explicit A(int value) {
        cout << "value" << endl;
    }
};

int main()
{
   // A a = 1; // error，不可以隐式转换
    A aa(2); // ok
    return 0;
}