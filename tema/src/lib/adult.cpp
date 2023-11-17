#include "adult.hpp"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <vector>

namespace PersonManager
{
    Adult::Adult() : Person()
    {
        std::cout << "Ai apelat constructorul default din Adult!" << std::endl;
    }

    Adult::~Adult()
    {
        std::cout << "Ai apelat destructorul din Adult!" << std::endl;
    }

    std::string Adult::getJob() const
    {
        return job;
    }

    void Adult::setJob(const std::string &job)
    {
        this->job = job;
    }

    void Adult::print() const
    {
        std::cout << "Nume: " << name << std::endl;
        std::cout << "Job: " << job << std::endl << std::endl;
    }

} // namespace PersonManager
