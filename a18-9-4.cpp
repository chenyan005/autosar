#include <iostream>
#include <utility>



int a = 0;
int b = std::forward<int>(a);
void print_and_increment(int& x) {
    std::cout << x << std::endl;
    ++x;
}

int main() {
    int value = 42;
    print_and_increment(std::forward<int&>(value)); // 这里违反了 Rule A18-9-4
    print_and_increment(value); // value 已经被 std::forward 使用过了

    return 0;
}

template <typename T1, typename T2>
void F1(T1 const& t1, T2& t2){
    t2=a;
// ...
};
template <typename T1, typename T2>
void F2(T1&& t1, T2&& t2)
{
    f1(std::forward<T1>(t1), std::forward<T2>(t2));
    ++t2; // Non-compliant
};