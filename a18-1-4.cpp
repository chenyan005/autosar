#include <cstdint>
#include <memory>
#include <vector>
void Fn() noexcept
{
    std::auto_ptr<std::int32_t> ptr1(new std::int32_t(10)); // Non-compliant
    std::unique_ptr<std::int32_t> ptr2 =std::make_unique<std::int32_t>(10); // Compliant
    std::vector<std::auto_ptr<std::int32_t>> v; // Non-compliant
}

#include <memory>
class MyClass {
public:
    MyClass(int val) : value(val) {}
    int value;
};

int main1() {
    MyClass* array = new MyClass[5];

    // 错误示例：将指向对象数组元素的指针传递给 std::unique_ptr
    std::unique_ptr<MyClass> ptr(array);
    std::unique_ptr<int> ptr1(new int[5]);// 违反规则

    return 0;
}


#include <memory>
#include <vector>

class MyClass1 {
public:
    MyClass1(int val) : value(val) {}
    int value;
};

int main() {
    std::vector<MyClass1> myObjects(5);  // 使用 std::vector 来管理对象数组

    return 0;
}

