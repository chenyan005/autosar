#include <cstdint>
class A
{
public:
    explicit A(std::uint32_t d): m_d(d)
    {

    }
    bool operator ==(A const & rhs) const // Non-compliant: member, not noexcept
    {
        return m_d == rhs.m_d;
    }
private:
    std::uint32_t m_d;
};

class C
{
public:
    operator A() const;
};

void Foo(A const & a, C const & c)
{
    a == c; // asymmetric as "a ==c" compiles, but "c == a" doesn’t compile
}
class B
{
public:
    explicit B(std::uint32_t d)
            : m_d(d)
    {

    }
   // Compliant: non-member, identical parameter types, noexcept
   friend bool operator==(B const & lhs, B const & rhs) noexcept
    {
        return lhs.m_d == rhs.m_d;
    }
private:
    std::uint32_t m_d;
};

class D
{
public:
    operator B() const;
};

void Bar(B const & b, D const & d)
{
    b == d;
    d == b;
}


#include <iostream>

class MyClass {
public:
    int data;

    // Incorrectly defined comparison operator as a member function
    bool operator==(const MyClass& other) noexcept {
        return data == other.data;
    }
};

int main() {
    MyClass obj1;
    obj1.data = 10;

    MyClass obj2;
    obj2.data = 20;

    if (obj1 == obj2) {
        std::cout << "Objects are equal." << std::endl;
    } else {
        std::cout << "Objects are not equal." << std::endl;
    }

    return 0;
}
