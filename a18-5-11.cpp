#include <cstdlib>

class A {
public:
    static void *operator new(std::size_t s); // Compliant: operator new
    static void operator delete(void *ptr); // defined together with
     // operator delete
};

class B {
public:
    static void *operator new(std::size_t s); // Non-compliant: operator
    static void * operator new [](std::size_t s); // new defined without
    // corresponding operator
    // delete
};