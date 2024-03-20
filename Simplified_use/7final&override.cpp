#include<iostream>
using namespace std;

class Base final { // Base 类被标记为 final，禁止继承
public:
    virtual void foo() final; // foo 函数被标记为 final，禁止重写
};

// class Derived : public Base { // 编译错误，Derived 试图继承 final 类 Base
// };

// class Derived : public Base {
// public:
//     void foo() override; // 编译错误，试图重写 final 函数 foo
// };

class Base1 {
public:
    virtual void foo(); // 基类中的虚函数
};

class Derived : public Base1 {
public:
    void foo() override; // 使用 override 明确表示重写基类中的虚函数
};


int main()
{
    return 0;
}