#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <bitset>



class Polynom {
private:
	static const int _POWER = 443;
	static const int _DOBLE_POWER = 2 * _POWER;
	std::bitset<_POWER> coefficients;
public:

	//Constr
	Polynom();
	Polynom(unsigned _default_num);
	Polynom(const std::string& binaryString);
	Polynom(const std::bitset<_POWER>& bitset_coeffs);
	~Polynom();

    std::string toBitString() const;

	//overloaded operators
	Polynom& operator=(const Polynom&);
	Polynom operator+(const Polynom&) const;
	Polynom operator*(const Polynom&) const;

    //
	static std::bitset<_DOBLE_POWER> double_pol(const std::bitset<_POWER >&);
	static std::bitset<_POWER> return_size(const std::bitset<_DOBLE_POWER>&);
	static void reduction(std::bitset<_DOBLE_POWER>&);
};

