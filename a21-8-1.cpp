#include <algorithm>
#include <cctype>
#include <string>

void RemoveDigits_Bad(std::string& s)
{
    s.erase(std::remove_if(s.begin(),s.end(),[](char c)  {
        return std::isdigit(c); // non-compliant
         }),
    s.cend());
}

void RemoveDigits_Good(std::string& s)
{
    s.erase(std::remove_if(s.begin(),s.end(),[](char c) {
        return std::isdigit(static_cast<unsigned char>(c)); // compliant
         }),
    s.cend());
}

void RemoveDigits_bad1(std::string& s)
{
    s.erase(std::remove_if(s.begin(),s.end(),[]() {
                return std::isdigit(static_cast<unsigned char>('a')); // compliant
            }),
            s.cend());
}