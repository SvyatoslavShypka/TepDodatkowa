#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag
//#include "CMyString.h"

class MyIterator : public std::iterator<std::input_iterator_tag, char>
{
    char* p;
public:
    MyIterator(char* x) :p(x) {}
    //MyIterator(CMyString x) :p(x.getM_Str()) {}
    MyIterator(const MyIterator& mit) : p(mit.p) {}
    MyIterator& operator++() { ++p; return *this; }
    MyIterator operator++(int) { MyIterator tmp(*this); operator++(); return tmp; }
    bool operator==(const MyIterator& rhs) const { return p == rhs.p; }
    bool operator!=(const MyIterator& rhs) const { return p != rhs.p; }
    char& operator*() { return *p; }
};
