#include <cstdint>
#include <vector>


const std::vector<int> constVector2 = {1, 2, 3, 4, 5};
std::vector<int>  = {1, 2, 3, 4, 5};
void Fn1( std::vector <std::int32_t> &v)noexcept{
     for (std::vector<std::int32_t>::const_iterator
     iter{v.cbegin()},end{v.cend()};iter !=end;++iter){

     } // Compliant
}

void Fn2(std::vector <std::int32_t> &v)noexcept{
      for (auto iter{v.cbegin()}, end{v.cend()};iter !=end;++iter){
      }

}

void Fn3(const std::vector <std::int32_t> &v)noexcept{
     for (std::vector<std::int32_t>::const_iterator iter{v.begin()},end{v.end()};iter !=end;++iter){
// ...
    }
}


void Fn4(std::vector <std::int32_t> &v)noexcept{
for (std::vector<std::int32_t>::const_iterator iter{v.begin()},end{v.end()};iter !=end;++iter){
// ...
}

}


#include <iostream>
#include <vector>

int main() {
    // 定义一个 const 容器
    std::vector<int> constVector = {1, 2, 3, 4, 5};

    // 使用 const_iterator 来遍历容器元素
    std::vector<int>:: iterator it = constVector.cbegin();

    while (it != constVector.end()) {
        std::cout << *it << " ";
        ++it;
    }

    return 0;
}
