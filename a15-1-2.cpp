#include <iostream>
#include <stdexcept>

void Function() {
    int* ptr = new int;
    throw std::move(ptr); // 违反规则 A15-1-2，抛出了指向对象的指针
}

int main() {
    try {
        Function();
    } catch (int* p) {
        std::cerr << "Caught exception: " << p << std::endl;
    }
    return 0;
}
