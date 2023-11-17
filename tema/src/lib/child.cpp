#include "child.hpp"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <vector>

namespace PersonManager
{
    Child::~Child()
    {
        std::cout << "Ai apelat destructorul din Child!" << std::endl;
    }

    std::string Child::getSchool() const
    {
        return school;
    }

    void Child::setSchool(const std::string &school)
    {
        this->school = school;
    }

    void Child::print() const
    {
        std::cout << "Nume: " << name << std::endl;
        std::cout << "Scoala: " << school << std::endl;
        std::cout << "Caracteristici: ";
        std::for_each(array, array + size, [](const char *str)
                      { std::cout << str << " "; });
        std::cout << std::endl << std::endl;
    }

} // namespace PersonManager
