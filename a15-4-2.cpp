#include <stdexcept>
#include <iostream>
#include <stdexcept>
// library.h
void LibraryFunc();
// project.cpp
void F1() noexcept
{
    throw std::runtime_error("Error");
}
void F2() noexcept(true)
{
try
{
// ...
throw std::runtime_error("Error"); // Compliant - exception will not leave f2
}
catch (std::runtime_error& e)
{
// Handle runtime error
}
}
void F3() noexcept(false)
{
// ...
    throw std::runtime_error("Error"); // Compliant
}
void F4() noexcept(false) // Compliant - no information whether library_func() throws or not
{
    LibraryFunc();
}


void MyFunction() noexcept {
    std::cout << "This is a noexcept function." << std::endl;

    throw std::runtime_error("An error occurred.");
}

int main() {
    try {
        MyFunction();
    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
