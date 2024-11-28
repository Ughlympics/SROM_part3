#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <bitset>



class Polynom {
private:
	static const int _POWER = 443;
	std::bitset<_POWER + 1> coefficients;
public:

	//Constr
	Polynom();
	Polynom(unsigned _default_num);
	Polynom(const std::string& binaryString);
	~Polynom();

    std::string toBitString() const;

	//overloaded operators
	Polynom& operator=(const Polynom&);
	Polynom operator+(const Polynom&) const;

};

