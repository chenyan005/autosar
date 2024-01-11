#include <utility>
class A
{
// Implementation
};
void F1()
{
    const A a1{};
    const int a=2;
    A a2 = a1; // Compliant - copy constructor is called
    A a3 = std::move(a1); // Non-compliant - copy constructor is called
    // implicitly instead of move constructor
    int a4 = std::move(a);
}

int func(const int& value){
    return std::move(value);
}
