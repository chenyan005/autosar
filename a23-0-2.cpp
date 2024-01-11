#include <algorithm>
#include <cstdint>
#include <list>
#include <vector>


void f() {
    std::vector <int32_t> v{0, 1, 2, 3, 4, 5, 6, 7};
    auto it = std::find(v.begin(), v.end(), 5); // *
    // These calls may lead to a reallocation of the vector storage
    // and thus may invalidate the iterator it.
    v.push_back(8);
    v.push_back(9);
    *it = 42; // Non-compliant
}


void g() {
    std::list <int32_t> l{0, 1, 2, 3, 4, 5, 6, 7};
    auto it = std::find(l.begin(), l.end(), 5); // *it is 5
    l.remove(7);
    l.push_back(9);
    *it = 42; // Compliant - previous operations do not invalidate iterators
    // l is now {0, 1, 2, 3, 4, 42, 6, 9 }
}

int func() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 遍历容器使用迭代器
    std::cout << "Using iterators:" << std::endl;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 使用引用访问容器元素
    std::cout << "Using references:" << std::endl;
    int& firstElement = numbers[0];
    std::cout << "First element: " << firstElement << std::endl;

    // 使用指针访问容器元素
    std::cout << "Using pointers:" << std::endl;
    int* lastElementPtr = &numbers.back();
    std::cout << "Last element: " << *lastElementPtr << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

int fun2() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用迭代器访问容器元素
    std::vector<int>::iterator it = numbers.begin();
    std::advance(it, 2); // 将迭代器移动到第三个元素
    int value = *it;

    std::cout << "Value: " << value << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

int func3() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 违反规则：使用超出容器范围的索引来访问元素
    int value = numbers[10]; // 超出了容器的大小

    std::cout << "Value: " << value << std::endl;

    return 0;
}


