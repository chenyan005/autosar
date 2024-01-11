#include <stdexcept>
void F1() noexcept{

}; // Compliant - note that noexcept is the same as
// noexcept(true)
void F2() throw(){

}; // Non-compliant - dynamic exception-specification is
// deprecated
void F3() noexcept(false){

}; // Compliant
void F4() throw(std::runtime_error){

}; // Non-compliant - dynamic
// exception-specification is deprecated
void F5() throw(...){

}; // Non-compliant - dynamic exception-specification is deprecated
template <class T>
void F6() noexcept(noexcept(T())){

}; // Compliant