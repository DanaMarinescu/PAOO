#include "person.hpp"
#include<iostream>
#include<cstring>

//implementarea metodelor clasei

//constructor default
Person::Person() : size(0), capacity(4), name("") {
    array = new char*[capacity];
    std::cout<<"Ai apelat constructorul default!"<<std::endl;
}

//destructor
Person::~Person() {
   for (int i = 0; i < size; i++) {
     delete[] array[i];
   }
   
   delete[] array;
   std::cout<<"Ai apelat destructorul!"<<std::endl;
}

//copy constructor
Person::Person(const Person& person) : size(person.size), capacity(person.capacity), name(person.name) {
    array = new char*[capacity];

    for (int i = 0; i < size; i++) {
        array[i] = new char[strlen(person.array[i]) + 1];
        strcpy(array[i], person.array[i]);
    }

    std::cout<<"Ai apelat copy constructor!"<<std::endl;
}

//move constructor
Person::Person(Person&& person) : size(person.size), capacity(person.capacity), name(person.name) {
    person.array = nullptr;
    person.size = 0;
    person.capacity = 0;
    person.name = "";
    std::cout<<"Ai apelat move constructor!"<<std::endl;
}

//functie pentru setarea numelui obiectului 'Person'
void Person::setName(const std::string& name) {
    this->name = name;
}

//functie pentru primirea numelui obiectului 'Person'
std::string Person::getName() const {
    return name;
}

//functie printare detalii obiect
void Person::print() const {
    std::cout<<"Nume: "<<name<<std::endl;
    std::cout<<"Caracteristici: ";
     for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

//functie de adaugat elemente in vector + resize daca e plin
void Person::add(const char* detail) {
 if (size == capacity) {
        //resize daca e plin
        capacity *= 2;
        char** newArray = new char*[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    //alocare memorie pentru noul string
    array[size] = new char[strlen(detail) + 1];
    strcpy(array[size], detail);
    size++;
}