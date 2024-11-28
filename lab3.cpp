#include "Polynom.h"
#include <iostream>

int main()
{
    Polynom f("101001");
    Polynom s("10100101");
    Polynom res;
    res = f + s;

    std::cout << "First pol: " << f.toBitString() << std::endl;
    std::cout << "Second pol: " << s.toBitString() << std::endl;
    std::cout << "Result: " << res.toBitString() << std::endl;
}


