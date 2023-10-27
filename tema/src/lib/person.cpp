#include "person.h"

Person::Person(const std::string& name) {
    //intializam 'name' in constructor
    this->name = name;
}

Person::~Person() {
    //destructor gol pentru ca 'name' gestioneaza automat propria memorie
}

Person::Person(const Person& person) {}

Person::Person(Person&& person) {}