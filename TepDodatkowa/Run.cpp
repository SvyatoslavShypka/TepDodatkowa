#include <iostream>
#include <cstring>
#include "CMyString.h"

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
    c_str2 = "";

    c_str = "Ala ma ";
    c_str += "kota ";
    c_str = c_str + "i psa";


    // Testowanie operatora rzutowania do bool
    rzutowanie(c_str);
    rzutowanie(c_str2);

    return 0;
}

