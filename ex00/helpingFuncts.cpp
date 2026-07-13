#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <iomanip>

void convertChar(char a) {
    //char part
    if (a >= 32 && a <= 126)
        std::cout << "char: " << a << "\n";
    else
        std::cout << "char: Non displayable\n";


    // int part
    int i = static_cast<int>(a);
    std::cout << "int: " << i << "\n";


    // float part
    float f = static_cast<float>(a);
    std::cout << "float: " << f << ".0f\n";


    // double part
    double d = static_cast<double>(a);
    std::cout << "double: " << d << ".0\n";
}

void convertInt(int i) {
    // char part
    if (i >= -128 && i <= 127) {
        if (i >= 32 && i <= 126)
            std::cout << "char: " << static_cast<char>(i) << "\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else {
        std::cout << "char: impossible\n";
    }


    // int part
    std::cout << "int: " << i << "\n";


    // float part
    std::cout << "float: ";
    float f = static_cast<float>(i);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << f << "f\n";

    // double part
    std::cout << "double: ";
    double d = static_cast<double>(i);
    std::cout << d << "\n";


    // undoing the stream manipulation
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << std::setprecision(6);
}

void convertFloat(float f) {
    // char part
    int i = static_cast<int>(f);
    if (i >= -128 && i <= 127) {
        if (i >= 32 && i <= 126)
            std::cout << "char: " << static_cast<char>(f) << "\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else {
        std::cout << "char: impossible\n";
    }


    // int part
    if (f != f || f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN)) {
        std::cout << "int: impossible\n";
    }
    else {
        std::cout << "int: " << i << "\n";
    }


    // float part
    std::cout << "float: ";
    if (f == i)
        std::cout << std::fixed << std::setprecision(1);
    std::cout << f << "f\n";


    // double part
    double d = static_cast<double>(f);
    std::cout << "double: " << d << "\n";


    // undoing the stream manipulation
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << std::setprecision(6);
}

void convertDouble(double d) {
    // char part
    int i = static_cast<int>(d);
    if (i >= -128 && i <= 127) {
        if (i >= 32 && i <= 126)
            std::cout << "char: " << static_cast<char>(d) << "\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else {
        std::cout << "char: impossible\n";
    }


    // int part
    if (d != d || d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN)) {
        std::cout << "int: impossible\n";
    }
    else {
        std::cout << "int: " << i << "\n";
    }


    // float part
    float f = static_cast<float>(d);
    std::cout << "float: ";
    if (f == i)
        std::cout << std::fixed << std::setprecision(1);
    std::cout << f << "f\n";


    // double part
    std::cout << "double: " << d << "\n";


    // undoing the stream manipulation
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << std::setprecision(6);
}

bool isChar(const std::string& literal) {
    if (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9')) {
        convertChar(literal[0]);
        return true;
    }
    return false;
}

bool isInt(const std::string& literal) {
    char *endPtr;
    long l = std::strtol(literal.c_str(), &endPtr, 10);
    if (*endPtr == '\0') {
        if (l > INT_MAX || l < INT_MIN)
            std::cerr << "Error: Integer Overflow/Undeflow\n";
        else {
            int i = static_cast<int>(l);
            convertInt(i);
        }
        return true;
    }
    return false;
}

bool isDoubleOrFloat(const std::string& literal) {
    char *endPtr;
    double d = std::strtod(literal.c_str(), &endPtr);
    if (*endPtr == '\0') {
        convertDouble(d);
        return true;
    }
    if ((*endPtr == 'f') && (*(endPtr + 1) == '\0')) {
        convertFloat(static_cast<float>(d));
        return true;
    }
    return false;
}

void isNone() {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}
