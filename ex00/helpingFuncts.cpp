#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <exception>

void convertChar(char a) {
    if (a >= 32 && a <= 126)
        std::cout << "char: " << a << "\n";
    else
        std::cout << "char: Non displayable\n";

    std::cout << "int: " << static_cast<int>(a) << "\n";

    std::cout << "float: " << static_cast<float>(a) << "f\n";

    std::cout << "double: " << static_cast<double>(a) << "\n";
}

void convertInt(int i) {
    if (i >= -128 && i <= 127) {
        if (i >= 32 && i <= 126)
            std::cout << "char: " << static_cast<char>(i) << "\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else {
        std::cout << "char: impossible\n";
    }

    std::cout << "int: " << i << "\n";

    std::cout << "float: " << static_cast<float>(i) << "f\n";

    std::cout << "double: " << static_cast<double>(i) << "\n";
}

void convertFloat(float f) {
    int i = static_cast<int>(f);
    if (i >= -128 && i <= 127) {
        if (i >= 32 && i <= 126)
            std::cout << "char: " << static_cast<char>(i) << "\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else {
        std::cout << "char: impossible\n";
    }

    std::cout << "int: " << i << "\n";

    std::cout << "float: " << f << "\n";

    std::cout << "double: " << static_cast<double>(f) << "\n";
}

void convertDouble(double d) {
    int i = static_cast<int>(d);
    if (i >= -128 && i <= 127) {
        if (i >= 32 && i <= 126)
            std::cout << "char: " << static_cast<char>(i) << "\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else {
        std::cout << "char: impossible\n";
    }

    std::cout << "int: " << i << "\n";

    std::cout << "float: " << static_cast<float>(d) << "\n";

    std::cout << "double: " << d << "\n";
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
    // if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
    //     literal == "-inff" || literal == "+inff" || literal == "nanf" ) {
    //         ;
    // }
    char *endPtr;
    double d = std::strtod(literal.c_str(), &endPtr);
    if (*endPtr == '\0') {
        convertDouble(d + 0.0);
        return true;
    }
    if ((*endPtr == 'f') && (*(endPtr + 1) == '\0')) {
        convertFloat(static_cast<float>(d) + 0.0);
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
