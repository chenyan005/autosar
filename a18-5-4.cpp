#include <iostream>
#include <new>

// 带大小的版本
void operator delete(void* ptr, std::size_t size) noexcept {
    std::cout << "Custom sized operator delete called. Size: " << size << std::endl;
    ::operator delete(ptr);
}

int main() {
    int* p = new int;

    // 使用带大小的 operator delete
    delete p(p,10); // 错误：没有定义带大小的 delete，违反了 Rule A18-5-4

    return 0;
}
