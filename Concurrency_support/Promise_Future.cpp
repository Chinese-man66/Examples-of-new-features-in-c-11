#include <iostream>
#include <thread>
#include <future>

using namespace std;

// 函数，接受一个 promise 对象并设置一个值
void compute_value(promise<int>& prom) {
    int result = 62;
    prom.set_value(result); // 设置值
}

int main() {
    promise<int> prom; // 创建一个 promise 对象
    future<int> fut = prom.get_future(); // 从 promise 获取与之关联的 future 对象

    thread t(compute_value, ref(prom)); // 在一个新线程中执行函数，并传入 promise 对象

    // 获取值，可能会等待
    int result = fut.get(); // 等待并获取 promise 设置的值

    cout << "Result: " << result << endl; // 输出结果

    t.join(); // 等待线程执行完成

    return 0;
}
