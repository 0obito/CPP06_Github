#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter& other);
        ScalarConverter& operator=(ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void convert(std::string& literal);
};

#endif /*SCALARCONVERTER_HPP*/
