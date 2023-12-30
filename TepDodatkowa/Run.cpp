#include <iostream>
#include "CMyString.h"
#include <string>
#include "MyIterator.h"

//using namespace std;

void rzutowanie(CMyString str) {

    if (str) {
        std::cout << MESSAGE_STRING_NOT_EMPTY << std::endl;
        std::cout << str.sToStandard() << std::endl;
        std::cout << MESSAGE_STRING_LENGTH << strlen(str.getM_Str()) << std::endl;
    }
    else {
        std::cout << MESSAGE_STRING_EMPTY << std::endl;
    }
}

int main() {
    // Testowanie klasy CMyString
    CMyString c_str;

    CMyString c_str2;
    c_str2 = STRING_EMPTY;

    c_str = STRING_ALA_MA;
    c_str += STRING_KOTA;
    c_str = c_str + STRING_I_PSA;


    // Testowanie operatora rzutowania do bool
    rzutowanie(c_str);
    rzutowanie(c_str2);

    string str("Test string iterator");
    for (string::iterator it = str.begin(); it != str.end(); ++it)
        cout << *it;
    cout << '\n';

    CMyString str3;
    str3 = "Test CMyString iterator";

    MyIterator from(str3.getM_Str());
    MyIterator until(str3.getM_Str() + str3.size());
    for (MyIterator it = from; it != until; it++)
        std::cout << *it << ' ';
    std::cout << '\n';

    CMyString str2;
    str2 = "Hello, World!";
    cout << str2.sToStandard() << endl;
    int length = str2.size();  // Returns the length of the string
    std::cout << "The length of the string is: " << length << std::endl;

    return 0;
}

