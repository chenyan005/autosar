#include <memory>
#include <cstdint>
#include <functional>
struct A
{
    A() { throw std::runtime_error("example");
    }
    A(std::uint8_t xx, std::uint8_t yy) : x(xx), y(yy)
    {

    }
    std::uint8_t x;
    std::uint8_t y;
};
void Foo(std::shared_ptr<A> a, std::shared_ptr<A> b) {

}
int main(void)
{
//compliant
    std::shared_ptr<A> upA = std::make_shared<A>(4,6);
//non-compliant
    std::shared_ptr<A> upA2 = std::shared_ptr<A>(new A(5,7));
//non-compliant, potential memory leak, as A class constructor throws
    Foo(std::shared_ptr<A>(new A()), std::shared_ptr<A>(new A()));
//non-compliant, potential memory leak, as A class constructor throws
    Foo(std::make_shared<A>(4,6), std::shared_ptr<A>(new A()));
//compliant, no memory leaks
    Foo(std::make_shared<A>(4,6), std::make_shared<A>(4,6));
//compliant by exception
    std::shared_ptr<A> ptr(new A(4,5), [](A*
    b) { delete b; } );
    return 0;
}
