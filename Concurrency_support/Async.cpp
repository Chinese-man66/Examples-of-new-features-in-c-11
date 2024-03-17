#include<iostream>
#include<future>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int main()
{
    future<int> result = async(add, 213424, 423252);// 启动异步操作，并获取与之关联的 std::future 对象

    auto sum = result.get();// 在主线程中等待异步操作完成，并获取结果

    cout << "sum : " << sum << endl;

    return 0;
}