#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 使用 auto 推断变量类型
    auto x = 5; // x 被推断为 int 类型
    auto y = 3.5; // y 被推断为 double 类型
    auto name = "John"; // name 被推断为 const char* 类型

    decltype (x) b;

    // 使用 auto 声明容器类型
    vector<int> numbers = {1, 2, 3, 4, 5};

    decltype(numbers) vec;
    vec.push_back(10);
    vec.push_back(20);

    

    for(auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << endl;
    }

    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;
    }

    for(auto x : (string)name) //自动便利每一位
    {
        cout << x << " " <<endl;
    }

    return 0;
}
