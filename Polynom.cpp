#include "Polynom.h"

#include <iostream>

//Constructors
Polynom::Polynom() {
    coefficients.reset(); 
}

Polynom::Polynom(unsigned _default_num) : coefficients{ _default_num }{}

Polynom::Polynom(const std::string& binaryString) {
    int ln = binaryString.size();

    if (ln > _POWER) {
        coefficients = 0b0; 
        throw std::invalid_argument("Binary string exceeds maximum degree");
    }

    int j = 0;
    for (auto i = binaryString.rbegin(); i != binaryString.rend(); ++i, ++j) {
        if (*i == '1') {
            coefficients[j] = 1;
        }
        else if (*i != '0') {
            coefficients = 0b0; 
            throw std::invalid_argument("Binary string contains invalid characters");
        }
    }
}

Polynom::~Polynom() {}

//output
std::string Polynom::toBitString() const {
    std::string bitString;
    for (int i = _POWER; i >= 0; --i) {
        bitString += coefficients[i] ? '1' : '0';
    }
    return bitString;
}

//overloaded operators
Polynom& Polynom::operator=(const Polynom& pol) {
    this->coefficients = pol.coefficients;
    return *this;
}

Polynom Polynom::operator+(const Polynom& pol) const {
    Polynom res;
    res.coefficients = this->coefficients ^ pol.coefficients;
    return res;
}

