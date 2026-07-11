#include "Data.hpp"

Data::Data() : _charData('0'), _intData(0), _strData("0") {
}

Data::Data(char c, int i, const std::string& s) : _charData(c), _intData(i), _strData(s) {
}

Data::Data(const Data& other) {
    _charData = other._charData;
    _intData = other._intData;
    _strData = other._strData;
}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        _charData = other._charData;
        _intData = other._intData;
        _strData = other._strData;
    }
    return *this;
}

Data::~Data() {
}

char Data::getChar() const {
    return _charData;
}

int Data::getInt() const {
    return _intData;
}

const std::string& Data::getStr() const {
    return _strData;
}
