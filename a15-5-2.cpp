#include <cstdlib>
#include <exception>
void F1() noexcept(false);
void F2() // Non-compliant
{
    F1(); // A call to throwing f1() may result in an implicit call to
// std::terminate()
}
void F3() // Compliant
{
    try
    {
        F1(); // Handles all exceptions from f1() and does not re-throw
    }
    catch (...)
    {
// Handle an exception
    }
}
void F4(const char*
log)
{
// Report a log error
// ...
    std::exit(0); // Call std::exit() function which safely cleans up resources
}
void F5() // Compliant by exception
{
    try
    {
        F1();
    }
    catch (...)
    {
        F4("f1() function failed");
    }
}
int main(int, char**
)
{
    if (std::atexit(&F2) != 0)
    {
// Handle an error
    }
    if (std::atexit(&F3) != 0)
    {
// Handle an error
    }
// ...
    return 0;
}
#include <stdexcept>

int main1() {
    // 未捕获的异常将导致 std::terminate() 隐式调用
    throw std::runtime_error("An error occurred.");
    return 0;
}
#include <cstdlib>

int main2(){
    // 不应该随意调用 std::abort()
    std::abort();
    return 0;
}
#include <cstdlib>

int main3() {
    // 不应该随意调用 std::quick_exit()
    std::quick_exit(0);
    return 0;
}
#include <cstdlib>

int main4() {
    // 不应该随意调用 std::_Exit()
    std::_Exit(0);
    return 0;
}


