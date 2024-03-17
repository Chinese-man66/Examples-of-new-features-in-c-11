#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int shared_data = 0;
mutex data_mutex;

void modify_data()
{
    lock_guard<mutex> lock(data_mutex);
    shared_data++;
}

int main()
{
    thread t1(modify_data);
    thread t2(modify_data);

    t1.join();
    t2.join();

    cout << "Shared data value : " << shared_data << endl;

    return 0;
}