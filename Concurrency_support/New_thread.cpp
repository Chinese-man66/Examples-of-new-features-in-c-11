#include<iostream>
#include<thread>

using namespace std;

void thread_info()
{
    cout << "here is thread !" << endl;
}

int main()
{
    thread t1(thread_info);//创建线程更加方便

    t1.join();

    cout << "Main thread exiting ..." << endl;

    return 0;
}