#include "lib/person.hpp"
#include<iostream>
#include<cstring>

int main() {
    Person person1;
    person1.setName("Dana");
    person1.add("scunda");
    person1.add("blonda");
    person1.add("22 de ani");
    person1.add("studenta");

//detalii inainte de move si copy
std::cout<<"Detalii pentru: (person1) "<<person1.getName()<<std::endl;
person1.print();

//copy constructor
    Person person2 = person1;

//detalii dupa copy
std::cout<<"Detalii pentru: (person1) "<<person1.getName()<<std::endl;
person1.print();

//move constructor
    Person person3(std::move(person1));

//afisare detalii final
std::cout<<"Detalii pentru: (person1) "<<person1.getName()<<std::endl;
person1.print();

std::cout<<"Detalii pentru: (person2) "<<person2.getName()<<std::endl;
person2.print();

std::cout<<"Detalii pentru: (person3) "<<person3.getName()<<std::endl;
person3.print();

return 0;
}