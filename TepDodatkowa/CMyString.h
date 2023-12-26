#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
            strcpy(m_str, other.m_str);
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
    CMyString& operator=(const char* str) {
        delete[] m_str;
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
        return *this;
    }

    // Przeciążony operator +=
    CMyString& operator+=(const char* str) {
        char* temp = new char[strlen(m_str) + strlen(str) + 1];
        strcpy(temp, m_str);
        strcat(temp, str);
        delete[] m_str;
        m_str = temp;
        return *this;
    }

    // Przeciążony operator +
    CMyString operator+(const char* str) const {
        CMyString result = *this;
        result += str;
        return result;
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

