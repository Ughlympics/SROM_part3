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

Polynom::Polynom(const std::bitset<_POWER>& bitset_coeffs) {
    coefficients = bitset_coeffs; 
}

Polynom::~Polynom() {}

//output
std::string Polynom::toBitString() const {
    std::string bitString;
    for (int i = _POWER - 1; i >= 0; --i) {
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

Polynom Polynom::operator*(const Polynom& pol) const {
    std::bitset<_DOBLE_POWER> res;

    std::bitset<_DOBLE_POWER> l = double_pol(this->coefficients);
    //std::bitset<_DOBLE_POWER> r = double_pol(pol.coefficients);

    for (int i = 0; i <= _POWER- 1; ++i, l <<= 1) {
        if (pol.coefficients[i]) {
            res ^= l; 
        }
    }

    reduction(res);
    return Polynom(return_size(res));
}

std::bitset<Polynom::_DOBLE_POWER> Polynom::double_pol(const std::bitset<_POWER>& pol) {
    std::bitset<Polynom::_DOBLE_POWER> doubled;
    for (int i = 0; i < _POWER; ++i)
        doubled[i] = pol[i];

    return doubled;
}

std::bitset<Polynom::_POWER> Polynom::return_size(const std::bitset<_DOBLE_POWER>& pol) {
    std::bitset<Polynom::_POWER> undoubled;
    for (int i = 0; i < _POWER; ++i)
        undoubled[i] = pol[i];

    return undoubled;
}

void Polynom::reduction(std::bitset<_DOBLE_POWER>& pol) {
    std::bitset<_DOBLE_POWER> p;
    p[_POWER] = p[28] = p[3] = p[1] = p[0] = 1;

    for (int i = _DOBLE_POWER - 1; i >= _POWER; --i) {
        if (pol[i])
            pol ^= (p << i - _POWER);
    }
}