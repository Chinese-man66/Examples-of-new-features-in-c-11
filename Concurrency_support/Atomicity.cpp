#include<iostream>
#include<atomic>
#include<thread>
using namespace std;

atomic<int> counter(0);

void increment()
{
    for(int i = 0; i < 1000; i++)
        counter.fetch_add(1, memory_order_relaxed);//原子操作，counter + 1;
}

int main()
{
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "counter value : " << counter << endl;

    return 0;
}