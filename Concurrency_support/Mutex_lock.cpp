#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print_block(int n, char c) 
{
    mtx.lock(); // 加锁

    for (int i = 0; i < n; ++i) 
        cout << c; // 访问共享资源

    cout << '\n';
    mtx.unlock(); // 解锁
}

int main() 
{
    thread t1(print_block, 50, '&');
    thread t2(print_block, 50, '$');

    t1.join();
    t2.join();

    return 0;
}
