#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

void runTest(const std::string& literal) {
    std::cout << "========================================\n";
    std::cout << " Input: [" << literal << "]\n";
    std::cout << "----------------------------------------\n";
    ScalarConverter::convert(literal);
    std::cout << "========================================\n\n";
}

int main(int argc, char **argv) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    else if (argc > 2) {
        std::cout << "Error: Too many arguments.\n";
        return 1;
    }

    runTest("z");
    runTest("C");
    runTest("*");

    runTest("0");
    runTest("42");
    runTest("-42");
    runTest("2147483647");
    runTest("-2147483648");

    runTest("0.0f");
    runTest("4.2f");
    runTest("-4.2f");
    runTest("4.21337f");

    runTest("0.0");
    runTest("4.2");
    runTest("-4.2");
    runTest("4.213371337");

    runTest("nan");
    runTest("+inf");
    runTest("-inf");

    runTest("nanf");
    runTest("+inff");
    runTest("-inff");

    runTest("2147483648");
    runTest("-2147483649");
    runTest("42.42.42");
    runTest("hello");
    runTest("");
    runTest("AF4213");
    runTest("42ACC7  adasjajh");

    std::cout << "[Complete]\n";
    return 0;
}
