#ifndef CHILD_HPP
#define CHILD_HPP

#include "person.hpp"

namespace PersonManager
{
    // subclasa Child a clasei de baza Person
    class Child : public Person
    {
    public:
        using Person::Person;
        ~Child() override;
        void print() const override;
        std::string getSchool() const;

    private:
        std::string school;
    };
} // namespace PersonManager

#endif