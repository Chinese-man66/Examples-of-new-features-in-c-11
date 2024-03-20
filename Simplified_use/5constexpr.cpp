#include<iostream>
using namespace std;

constexpr int func(int i) {
    return i + 1;
}

int main() {
    int i = 2;
    cout << func(i) << endl;// 普通函数
    cout << func(2) << endl;// 编译期间就会被计算出来
}