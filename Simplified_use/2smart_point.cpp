#include <iostream>
#include <memory>

using namespace std;

class Resource {
public:
    Resource() {
        cout << "Resource acquired" << endl;
    }

    ~Resource() {
        cout << "Resource released" << endl;
    }

    void doSomething() {
        cout << "Resource is doing something" << endl;
    }
};

class A;
class B;

class A {
public:
    shared_ptr<B> b_ptr;
};

class B {
public:
    weak_ptr<A> a_ptr;
};

int main() {
    // 使用unique_ptr 确保资源在函数结束后被释放
    {
        unique_ptr<Resource> uniquePtr = make_unique<Resource>();
        uniquePtr->doSomething();
    } // uniquePtr 超出作用域，资源自动释放

    cout << endl;

    // 使用shared_ptr 实现资源共享
    {
        shared_ptr<Resource> sharedPtr = make_shared<Resource>();
        sharedPtr->doSomething();

        shared_ptr<Resource> sharedPtr2 = sharedPtr; // 共享资源
        sharedPtr2->doSomething();
    } // sharedPtr 和 sharedPtr2 超出作用域，资源计数为零，资源自动释放

    cout << endl;

    // 使用weak_ptr 解决循环引用问题
    {
        auto a = make_shared<A>();
        auto b = make_shared<B>();
        a->b_ptr = b;
        b->a_ptr = a;
    } // a 和 b 超出作用域，资源自动释放

    return 0;
}
