#include <iostream>
#include "CMyString.h"
#include <string>

void rzutowanie(CMyString str) {

    if (str) {
        std::cout << "Obiekt CMyString nie jest pusty." << std::endl;
        std::cout << str.sToStandard() << std::endl;
        std::cout << "Dlugosc CMyString: " << strlen(str.getM_Str()) << std::endl;
    }
    else {
        std::cout << "Obiekt CMyString jest pusty." << std::endl;
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

    std::string str("Test string");
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
        std::cout << *it;
    std::cout << '\n';

    return 0;
}

