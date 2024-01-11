#include <cstdint>
#include <string>
#include <utility>
#include <iostream>
#include <utility>

class A {
   public:explicit A(std::string &&s): str(std::move(s)) // Compliant - forwarding rvalue reference
    {
    }
private:
    std::string str;
};

class B {
};

void Fn1(const B &lval,int b) {
}
void fn1(int&& a){
    std::cout << "Received a right-value: " << a << std::endl;
}
void fn2(int&& a){
    fn1(std::move(a));
}

template<typename T>
void Fn2(T &&param) {
    Fn1(std::forward<T>(param),2); // Compliant - forwarding forwarding reference
}

template<typename T>
void Fn3(T &&param) {
    Fn1(std::move(param),2); // Non-compliant - forwarding forwarding reference
    Fn1(std::forward<T>(param),2);
    // via std::move
}

void Fn4() noexcept {
    B b1;
    B &b2 = b1;
    Fn2(b2); // fn1(const B&) is called
    Fn2(std::move(b1)); // fn1(B&&) is called
    Fn3(b2); // fn1(B&&) is called
    Fn3(std::move(b1)); // fn1(B&&) is called
}





void AnotherFunction(int&& value) {
    // 处理右值
    std::cout << "Received a right-value: " << value << std::endl;
}
void AnotherFunction3(int& value) {
    // 处理右值
    std::cout << "Received a right-value: " << value << std::endl;
}
void ProcessValue(int&& value) {
    // 在这里可以使用std::move将右值引用传递给其他函数
    AnotherFunction(std::move(value));
    AnotherFunction(value);
    AnotherFunction3(value);
}

void ProcessValue3(int& value) {
    // 在这里可以使用std::move将右值引用传递给其他函数
    AnotherFunction(std::move(value));
    AnotherFunction(value);
    AnotherFunction3(std::move(value));
    AnotherFunction3(value);
}



int main() {
    int num = 42;
    // 使用std::move将右值引用传递给ProcessValue函数
    ProcessValue(std::move(num));

    return 0;
}


#include <iostream>
#include <utility>
void AnotherFunction1(const int& value) {
    std::cout << "Received an l-value: " << value << std::endl;
}

void AnotherFunction1(int&& value) {
    std::cout << "Received a right-value: " << value << std::endl;
}
template <typename T>
void ProcessValue1(T&& value,int& value2) {
    // 使用std::forward将转发引用传递给其他函数
    AnotherFunction1(std::forward<T>(value));
    AnotherFunction1(value2);
}
int mai2() {
    int num = 42;
    // 使用转发引用将左值传递给ProcessValue函数
    ProcessValue1(num,num);
    // 使用转发引用将右值传递给ProcessValue函数
    ProcessValue1(123,num);
    return 0;
}

