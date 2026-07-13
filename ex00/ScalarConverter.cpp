#include "ScalarConverter.hpp"

bool isChar(const std::string& literal);
bool isInt(const std::string& literal);
bool isDoubleOrFloat(const std::string& literal);
void isNone();

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.length() < 1)
        return isNone();
    if (isChar(literal))
        return ;
    else if (isInt(literal))
        return ;
    else if (isDoubleOrFloat(literal))
        return ;
    return isNone();
}
