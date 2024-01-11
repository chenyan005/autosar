#include <stdexcept>
#include <thread>
extern bool F1();
class A
{
public:A() noexcept(false)
    {
// ...
        throw std::runtime_error("Error1");
    }
    ~A(){
// ...
        throw std::runtime_error("Error2"); // Non-compliant - std::terminate()
        // called on throwing an exception
        // from noexcept(true) destructor
    }
};
class B
{
public:
    ~B() noexcept(false)
    {
// ...
        throw std::runtime_error("Error3");
    }
};
void F2()
{
    throw std::runtime_error("123");
}
void ThreadFunc()
{
    A a; // Throws an exception from a’s constructor and does not handle it in
// thread_func()
}
void F3()
{
    try
    {
        std::thread t(&ThreadFunc); // Non-compliant - std::terminate() called
        // on throwing an exception from
        // thread_func()
        if (F1())
        {
            throw std::logic_error("Error4");
        }
        else
        {
            F2(); // Non-compliant - std::terminate() called if there is no
            // active exception to be re-thrown by f2
        }
    }
    catch (...)
    {
        B b; // Non-compliant - std::terminate() called on throwing an
        // exception from b’s destructor during exception handling
// ...
        F2();
    }
}
static A a; // Non-compliant - std::terminate() called on throwing an exception
// during program’s start-up phase
int main(int, char**
)
{
    F3(); // Non-compliant - std::terminate() called if std::logic_error is
// thrown
    return 0;
}