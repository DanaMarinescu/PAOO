#include "person.hpp"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <vector>

namespace PersonManager
{
    // implementarea metodelor clasei

    // constructor default
    Person::Person() : size(0), capacity(4), name("")
    {
        array = new char *[capacity];
        std::cout << "Ai apelat constructorul default!" << std::endl;
    }

    // destructor
    Person::~Person()
    {
        delete[] array;
        std::cout << "Ai apelat destructorul!" << std::endl;
    }

    // copy constructor
    Person::Person(const Person &person) : size(person.size), capacity(person.capacity), name(person.name)
    {
        array = new char *[capacity];

        std::copy(person.array, person.array + size, array);

        std::cout << "Ai apelat copy constructor!" << std::endl;
    }

    // copy assignment operator
    Person &Person::operator=(const Person &person)
    {
        if (this != &person)
        {
            delete[] array;

            // copiem valorile din partea dreapta a operatorul, in obiectul din partea stanga a acestuia
            size = person.size;
            capacity = person.capacity;
            name = person.name;

            array = new char *[capacity];
            std::copy(person.array, person.array + size, array);
        }

        std::cout << "Ai folosit copy assignment operator!" << std::endl;
        return *this;
    }

    // move constructor
    Person::Person(Person &&person) : size(person.size), capacity(person.capacity), name(std::move(person.name))
    {
        array = person.array;   // nu reseteaza obiectul sursa, doar muta pointerul la el
        person.array = nullptr; // dupa mutare pointer, resetam obiectul
        person.size = 0;
        person.capacity = 0;

        std::cout << "Ai apelat move constructor!" << std::endl;
    }

    // move assignment operator
    Person &Person::operator=(Person &&person)
    {
        if (this != &person)
        {
            delete[] array;

            // copiem valorile din partea dreapta a operatorul, in obiectul din partea stanga a acestuia
            name = std::move(person.name);
            size = person.size;
            capacity = person.capacity;
            array = person.array;

            // resetare obiect din care mutam
            person.size = 0;
            person.capacity = 0;
            person.name = "";
            person.array = nullptr;
        }

        std::cout << "Ai folosit move assignment operator!" << std::endl;
        return *this;
    }

    // functie pentru setarea numelui obiectului 'Person'
    void Person::setName(const std::string &name)
    {
        this->name = name;
    }

    // functie pentru primirea numelui obiectului 'Person'
    std::string Person::getName() const
    {
        return name;
    }

    // functie printare detalii obiect
    void Person::print() const
    {
        std::cout << "Nume: " << name << std::endl;
        std::cout << "Caracteristici: ";
        std::for_each(array, array + size, [](const char *str)
                      { std::cout << str << " "; });
        std::cout << std::endl
                  << std::endl;
    }

    // functie de adaugat elemente in vector + resize daca e plin
    void Person::add(const char *detail)
    {
        if (size == capacity)
        {
            // resize daca e plin
            capacity *= 2;
            std::vector<char *> newArray(array, array + size);
            array = new char *[capacity];
            std::copy(newArray.begin(), newArray.end(), array);
        }

        // alocare memorie pentru noul string
        array[size] = new char[strlen(detail) + 1];
        strcpy(array[size], detail);
        size++;
    }

} // namespace PersonManager