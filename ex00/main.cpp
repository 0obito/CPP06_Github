#include <iostream>
#include <string>
#include <climits>

// int main() {
//     char c = 255;
//     int i = 127;
//     float f = 42.1;
//     double d = 42.2;

//     char cc;
//     int ii;
//     float ff;
//     double dd;

//     cc = static_cast<char>(c);
//     std::cout<<c<<'\n';
//     ii = static_cast<int>(c);
//     std::cout<<ii<<'\n';
//     ff = static_cast<float>(c);
//     std::cout<<ff<<"f\n";
//     dd = static_cast<double>(c);
//     std::cout<<dd<<'\n';

//     cc = static_cast<char>(i);
//     std::cout<<cc<<'\n';
//     ii = static_cast<int>(i);
//     std::cout<<ii<<'\n';
//     ff = static_cast<float>(i);
//     std::cout<<ff<<"f\n";
//     dd = static_cast<double>(i);
//     std::cout<<dd<<'\n';

//     cc = static_cast<char>(f);
//     std::cout<<cc<<'\n';
//     ii = static_cast<int>(f);
//     std::cout<<ii<<'\n';
//     ff = static_cast<float>(f);
//     std::cout<<ff<<"f\n";
//     dd = static_cast<double>(f);
//     std::cout<<dd<<'\n';

//     cc = static_cast<char>(d);
//     std::cout<<cc<<'\n';
//     ii = static_cast<int>(d);
//     std::cout<<ii<<'\n';
//     ff = static_cast<float>(d);
//     std::cout<<ff<<"f\n";
//     dd = static_cast<double>(d);
//     std::cout<<dd<<'\n';
// }

// #include <limits>
// #include <cmath> // For std::sqrt

// int main() {
//     // 1. ASSIGNMENT USING C++98 STANDARD (<limits>)
    
//     // Positive and Negative Infinity
//     double pos_inf = std::numeric_limits<double>::infinity();
//     double neg_inf = -std::numeric_limits<double>::infinity();
    
//     // Not a Number (double and float variants)
//     double my_nan   = std::numeric_limits<double>::quiet_NaN();
//     float  my_nanf  = std::numeric_limits<float>::quiet_NaN();

//     // Print assigned values
//     std::cout << "Assigned +inf: " << pos_inf << "\n";
//     std::cout << "Assigned -inf: " << neg_inf << "\n";
//     std::cout << "Assigned nan:  " << my_nan << "\n";
//     std::cout << "Assigned nanf: " << my_nanf << "\n\n";

//     // 2. HOW TO USE / CHECK THEM IN C++98
    
//     double normal_num = 42.0;

//     // Checking for Infinity
//     // In C++98, infinity equals itself.
//     if (pos_inf == std::numeric_limits<double>::infinity()) {
//         std::cout << "Value is positive infinity.\n";
//     }

//     // Checking for NaN
//     // Crucial rule: NaN never equals anything, including itself!
//     // Therefore, (x != x) is the standard C++98 trick to detect NaN.
//     if (my_nan != my_nan) {
//         std::cout << "Value is NaN (detected via my_nan != my_nan).\n";
//     }

//     // Comparing a normal number to NaN always returns false
//     if (normal_num < my_nan || normal_num > my_nan || normal_num == my_nan) {
//         // This block will never execute
//     } else {
//         std::cout << "Comparisons with NaN always fail.\n\n";
//     }

//     // 3. MATHEMATICAL BEHAVIOR
    
//     std::cout << "Infinity + 5: " << (pos_inf + 5.0) << "\n"; 
//     std::cout << "Infinity * 0: " << (pos_inf * 0.0) << "\n"; // Results in NaN
//     std::cout << "NaN + 5:       " << (my_nan + 5.0) << "\n";  // Operations on NaN stay NaN

//     return 0;
// }

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

// Helper function to make the output highly readable
void runTest(const std::string& literal, const std::string& description) {
    std::cout << "========================================\n";
    std::cout << " Test: " << description << "\n";
    std::cout << " Input: [" << literal << "]\n";
    std::cout << "----------------------------------------\n";
    ScalarConverter::convert(literal);
    std::cout << "========================================\n\n";
}

int main(int argc, char **argv) {
    // 1. The Strict Subject Requirement (Manual Mode)
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    else if (argc > 2) {
        std::cout << "Error: Too many arguments.\n";
        return 1;
    }

    // 2. The Automated Test Suite (Triggered by running with 0 arguments)
    std::cout << "\n[ STARTING SCALAR CONVERTER TEST SUITE ]\n\n";

    // --- CHARACTERS ---
    runTest("c", "Standard Char");
    runTest("a", "Standard Char");
    runTest("*", "Printable Symbol");

    // --- INTEGERS ---
    runTest("0", "Zero Int");
    runTest("42", "Positive Int");
    runTest("-42", "Negative Int");
    runTest("2147483647", "Int Max");
    runTest("-2147483648", "Int Min");

    // --- FLOATS ---
    runTest("0.0f", "Zero Float");
    runTest("4.2f", "Standard Float");
    runTest("-4.2f", "Negative Float");
    runTest("4.22222f", "Float Precision");

    // --- DOUBLES ---
    runTest("0.0", "Zero Double");
    runTest("4.2", "Standard Double");
    runTest("-4.2", "Negative Double");
    runTest("4.2222222222", "Double Precision");

    // --- PSEUDO-LITERALS (The Weird Limits) ---
    runTest("nan", "Double NaN");
    runTest("nanf", "Float NaN");
    runTest("+inf", "Double Positive Infinity");
    runTest("-inf", "Double Negative Infinity");
    runTest("+inff", "Float Positive Infinity");
    runTest("-inff", "Float Negative Infinity");

    // --- EDGE CASES & GARBAGE (Where code usually breaks) ---
    runTest("2147483648", "Int Overflow (Should parse as Double/Float)");
    runTest("-2147483649", "Int Underflow (Should parse as Double/Float)");
    runTest("42.42.42", "Multiple Decimals (Invalid)");
    runTest("42f", "Missing Decimal for Float (Invalid)");
    runTest("hello", "Pure String Garbage");
    runTest("", "Empty String");
    runTest("  42", "Leading Spaces");
    runTest("42  ", "Trailing Spaces");

    std::cout << "[ TEST SUITE COMPLETE ]\n";
    return 0;
}