#include <string>

using namespace std;


const std::string MESSAGE_NORMAL_OPERATOR = "Normal operator=";
const std::string MESSAGE_MS_OPERATOR = "MS operator=";
const std::string MESSAGE_OPERATOR_PLUS = "Operator +";
const std::string MESSAGE_OPERATOR_PLUS_EQUAL = "Operator +=";
const char* STRING_EMPTY = "";
const char* STRING_ALA_MA = "Ala ma ";
const char* STRING_KOTA = "kota ";
const char* STRING_I_PSA = "i psa";
const char SYMBOL_NULL_TERMINATED = '\0';

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

    char* getM_Str() {
        return m_str;
    }

    // Przeciążony operator przypisania =
    void operator=(const char* str) {
        //std::cout << MESSAGE_NORMAL_OPERATOR << std::endl;
        delete[] m_str;
        size_t length = strlen(str) + 1;
        m_str = new char[length];
        strcpy_s(m_str, length, str);
    }

    // Przeciążony operator przypisania =
    CMyString& operator=(const string& str) {
        //std::cout << MESSAGE_NORMAL_OPERATOR << std::endl;
        delete[] m_str;
        size_t length = str.size();
        m_str = new char[length];
        char arr[200];
        for (int i = 0; i < length && str[i] != '\0'; i++) {
            m_str[i] = str[i];
        }
        return(*this);
    }

    // Move Semantics
    void operator=(CMyString&& str) {
        //std::cout << MESSAGE_MS_OPERATOR << std::endl;
        delete[] m_str;
        size_t length = strlen(str.m_str) + 1;
        m_str = new char[length];
        strcpy_s(m_str, length, str.m_str);
    }

    // Przeciążony operator +=
    CMyString& operator+=(const char* str) {
        //std::cout << MESSAGE_OPERATOR_PLUS_EQUAL << std::endl;
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
        //std::cout << MESSAGE_OPERATOR_PLUS << std::endl;
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
        return m_str != nullptr && m_str[0] != SYMBOL_NULL_TERMINATED;
    }

    //size
    int size() {
        return sizeof(m_str)/sizeof(m_str[0]);
    }
};

