#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string> 
#include <vector> 
#include <sstream>
#include <queue>

class CMyString {
private:
    char* m_str;

public:
    // Konstruktor bezparametrowy
    CMyString() : m_str(nullptr) {}

    // Konstruktor kopiujący
    CMyString(const CMyString& other) {
        if (other.m_str != nullptr) {
            m_str = new char[strlen(other.m_str) + 1];
            strcpy_s(m_str, strlen(other.m_str) + 1, other.m_str);
        }
        else {
            m_str = nullptr;
        }
    }

    // Destruktor
    ~CMyString() {
        delete[] m_str;
    }

    // Przeciążony operator przypisania =
    void operator=(const char* str) {
        delete[] m_str;
        size_t length = strlen(str) + 1;
        m_str = new char[length];
        strcpy_s(m_str, length, str);
        //return *this;
    }

    void operator=(char&& str) {
        std::cout << "MS" << std::endl;
        delete[] m_str;
        size_t length = strlen(&str) + 1;
        m_str = new char[length];
        strcpy_s(m_str, length, &str);
        //return *this;
    }

    //// Przeciążony operator przypisania =
    //CMyString& operator=(const char* str) {
    //    delete[] m_str;
    //    size_t length = strlen(str) + 1;
    //    m_str = new char[length];
    //    strcpy_s(m_str, length, str);
    //    return *this;
    //}

    // Przeciążony operator +=
    CMyString& operator+=(const char* str) {
        size_t newLength = strlen(m_str) + strlen(str) + 1;
        char* temp = new char[newLength];
        strcpy_s(temp, newLength, m_str);
        strcat_s(temp, newLength, str);
        delete[] m_str;
        m_str = temp;
        return *this;
    }

    // Przeciążony operator +
    CMyString operator+(const char* str) const {
        CMyString result(*this);
        result += str;
        return std::move(result);
    }

    // Metoda sToStandard
    std::string sToStandard() const {
        return m_str != nullptr ? std::string(m_str) : std::string();
    }

    // Przeciążony operator rzutowania do bool
    operator bool() const {
        return m_str != nullptr && m_str[0] != '\0';
    }
};

