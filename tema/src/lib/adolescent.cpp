#include "adolescent.hpp"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <vector>

namespace PersonManager
{
    Adolescent::Adolescent(const std::int16_t &age) : Person(), age(age)
    {
        std::cout << "Ai apelat constructorul default din Adolescent!" << std::endl;
    }

    Adolescent::~Adolescent()
    { 
        std::cout << "Ai apelat destructorul din Adolescent!" << std::endl;
    }

    std::string Adolescent::getHighSchool() const
    {
        return highSchool;
    }

    void Adolescent::setHighSchool(const std::string &highSchool)
    {
        this->highSchool = highSchool;
    }

    std::int16_t Adolescent::getAge() const
    {
        return age;
    }

    void Adolescent::setAge(const std::int16_t &age)
    {
        this->age = age;
    }

    void Adolescent::print() const
    {
        std::cout << "Nume: " << name << std::endl;
        std::cout << "Liceu: " << highSchool << std::endl;
        std::cout << "Varsta: " << age << std::endl << std::endl;
    }

} // namespace PersonManager
