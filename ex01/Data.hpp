#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data {
    private:
        char        _charData;
        int         _intData;
        std::string _strData;
    public:
        Data();
        Data(char c, int i, const std::string& s);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();

        char getChar() const;
        int getInt() const;
        const std::string& getStr() const;
};

#endif /*DATA_HPP*/
