#include <memory>

template <template <typename> class T, typename U>
struct Base
{
    T<U> sp;
};
template <typename T>
using Shared = Base<std::shared_ptr, T>;
template <typename T>
using Weak = Base<std::weak_ptr, T>;
struct SBarSFoo;
struct SFooSBar : public Shared<SBarSFoo> {};
struct SBarSFoo : public Shared<SFooSBar> {};
struct A : public Shared<A> {};
struct WBarSFoo;
struct SFooWBar : public Shared<WBarSFoo> {};
struct WBarSFoo : public Weak<SFooWBar> {};

int main()
{
    std::shared_ptr<SFooSBar> f = std::make_shared<SFooSBar>();
    std::shared_ptr<SBarSFoo> b = std::make_shared<SBarSFoo>();
    f->sp = b;
    b->sp = f;
    //non-compliant, both f and b have ref_count() == 2
//destructors of f and b reduce ref_count() to 1,
//destructors of underlying objects are never called,
//so destructors of shared_ptrs sp are not called
//and memory is leaked

    std::shared_ptr<A> a = std::make_shared<A>();
    a->sp = a;
//non-compliant, object ’a’ destructor does not call
//underlying memory destructor
    std::shared_ptr<SFooWBar> f2 = std::make_shared<SFooWBar>();
    std::shared_ptr<WBarSFoo> b2 = std::make_shared<WBarSFoo>();
    f2->sp = b2;
    b2->sp = f2;

//compliant, b2->sp holds weak_ptr to f2, so f2 destructor
//is able to properly destroy underlying object
    return 0;
}


#include <iostream>
#include <memory>

class Widget {
public:
    Widget(int data) : data(data) {}

    void printData() {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

int func() {
    std::shared_ptr<Widget> sharedWidget = std::make_shared<Widget>(42);

    // 不正确的使用：没有 std::weak_ptr，共享所有权不会自动结束
    std::shared_ptr<Widget> incorrectShared = sharedWidget;

    incorrectShared->printData();

    // sharedWidget 和 incorrectShared 都继续共享所有权
    // 对象的销毁可能延迟，违反规则
    return 0;
}


#include <iostream>
#include <memory>

class Base1 {
public:
    Base1(int data) : data(data) {}

    void printData() {
        std::cout << "Base Data: " << data << std::endl;
    }

private:
    int data;
};

class Derived : public std::weak_ptr<Base1> {
public:
    Derived(std::shared_ptr<Base1> base) : std::weak_ptr<Base1>(base) {}

    void doSomething() {
        // 使用 lock() 检查基类对象是否仍然存在
        if (auto sharedBase = lock()) {
            sharedBase->printData();
        } else {
            std::cout << "Base object no longer exists." << std::endl;
        }
    }
};

int func2() {
    std::shared_ptr<Base1> base = std::make_shared<Base1>(42);

    Derived derived(base);
    derived.doSomething();

    // 等待基类对象超出作用域
    base.reset();

    derived.doSomething(); // 输出 "Base object no longer exists."

    return 0;
}

