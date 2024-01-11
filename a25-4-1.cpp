#include <functional>
#include <iostream>
#include <set>


// 自定义比较谓词，满足严格的弱排序关系
bool CustomComparator(int a, int b) {
    // 以下条件满足严格的弱排序关系：
    // 1. 反对称性：如果 a < b 为真，则 b < a 必须为假。
    // 2. 传递性：如果 a < b 为真且 b < c 为真，则 a < c 必须为真。
    // 3. 反自反性：a < a 必须为假。
    return a >= b;
}

int func() {
    std::vector<int> numbers = {5, 2, 8, 1, 6, 3, 4, 7};

    // 使用自定义比较谓词进行排序
    std::sort(numbers.begin(), numbers.end(), CustomComparator);

    // 打印排序后的结果
    for (const int& num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}


int main(void) {
     //non-compliant, given predicate does not return false
     //for equal values
    std::set<int, std::greater_equal<int>> s{2, 5, 8};
    auto r = s.equal_range(5);
    //returns 0
    std::cout << std::distance(r.first, r.second) << std::endl;
    //compliant, using default std::less<int>
    std::set<int> s2{2, 5, 8};
    auto r2 = s2.equal_range(5);
     //returns 1
    std::cout << std::distance(r2.first, r2.second) << std::endl;
    return 0
}