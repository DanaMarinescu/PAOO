//previne ca acelasi fisier header sa fie inclus de mai multe ori in procesul de compilare
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <string>
#include <algorithm>
#include "IPerson.hpp"

namespace PersonManager
{

    class Person : public IPerson
    {
    public:
        // constructor default
        Person();

        // functii specifice pentru clasa 'Person'
        void setName(const std::string &name);
        std::string getName() const;
        void print() const override;
        void add(const char *detail);

        virtual ~Person(); // Virtual destructor

        // copy constructor ce implica deep copy
        Person(const Person &person);

        // move constructor ce implica shallow copy
        Person(Person &&person);

        // copy assignment operator
        Person &operator=(const Person &person);

        // move assignment operator
        Person &operator=(Person &&person);

    protected:
        std::string name;
        char **array;
        int size;
        int capacity;
    };
} // namespace PersonManager

#endif