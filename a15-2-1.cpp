#include <iostream>
#include <cstdint>
#include <stdexcept>
// 非 noexcept 的构造函数
class MyObject {
public:
    MyObject() {
        // 在构造函数中可能会引发异常
        if (a/b) {
            throw std::runtime_error("An error occurred in constructor");
        }
    }
private:
    int a;
    int b;
};

// 在程序启动之前创建 MyObject 对象
MyObject obj; // 违反规则：非 noexcept 的构造函数在程序启动之前被调用

class A
{
public:
    A() noexcept : x(0)
    {
// ...
    }
    explicit A(std::int32_t n) : x(n)
    {
// ...
        throw std::runtime_error("Unexpected error");
    }
    A(std::int32_t i, std::int32_t j) noexcept : x(i + j)
    {
        try
        {
             // ...
            throw std::runtime_error("Error");
            // ...
        }

        catch (std::exception& e)
        {
        }
    }
private:
    std::int32_t x;
};
static A a1; // Compliant - default constructor of type A is noexcept
static A a2(5); // Non-compliant - constructor of type A throws, and the
// exception will not be caught by the handler in main function
static A a3(5, 10); // Compliant - constructor of type A is noexcept, it
// handles exceptions internally
int main(int, char**
)
{
    try
    {
// program code
    }
    catch (...)
    {
// Handle exceptions
    }
    return 0;
}