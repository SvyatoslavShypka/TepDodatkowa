#include <iostream>
#include <cstring>
#include "CMyString.h"


int main() {
    // Testowanie klasy CMyString
    CMyString c_str;
    c_str = "ma ";
    c_str += "kota ";
    c_str = c_str + "i psa";

    // Wartość obiektu c_str powinna być "ma kota i psa"
    std::cout << c_str.sToStandard() << std::endl;

    // Testowanie operatora rzutowania do bool
    if (c_str) {
        std::cout << "Obiekt CMyString nie jest pusty." << std::endl;
    }
    else {
        std::cout << "Obiekt CMyString jest pusty." << std::endl;
    }

    return 0;
}
