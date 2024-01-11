#include <iostream>
#include <clocale>
#include <cstdlib>
int main() {
    // 错误示例：使用 <clocale> 和 setlocale 进行本地化设置
    setlocale(LC_ALL, "en_US.UTF-8");

    // 输出一些本地化的文本
    std::cout << "Hello, World!" << std::endl;

    return 0;
}



