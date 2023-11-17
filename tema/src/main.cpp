#include "lib/person.hpp"
#include "lib/child.hpp"
#include "lib/adolescent.hpp"
#include "lib/adult.hpp"

#include <iostream>
#include <cstring>

int main()
{
    PersonManager::Person person1;
    person1.setName("Dana");
    person1.add("scunda");
    person1.add("blonda");
    person1.add("22 de ani");
    person1.add("studenta");

    // detalii inainte de move si copy
    std::cout << "Detalii pentru: (person1) " << person1.getName() << std::endl;
    person1.print();

    // copy constructor
    PersonManager::Person person2 = person1;

    // detalii dupa copy
    std::cout << "Detalii pentru: (person1) " << person1.getName() << std::endl;
    person1.print();

    // move constructor
    PersonManager::Person person3(std::move(person1));

    // afisare detalii final
    std::cout << "Detalii pentru: (person1) " << person1.getName() << std::endl;
    person1.print();

    std::cout << "Detalii pentru: (person2) " << person2.getName() << std::endl;
    person2.print();

    std::cout << "Detalii pentru: (person3) " << person3.getName() << std::endl;
    person3.print();

    std::cout << "------------TEMA 2------------" << std::endl <<std::endl;

    PersonManager::Person person4;
    person4.setName("Ionel");
    person4.add("inalt");
    person4.add("brunet");
    person4.add("studenta");

    // cream un obiect Person folosind move operator
    PersonManager::Person person5;
    person5 = std::move(person4);

    std::cout << "Detalii pentru person 5: " << person5.getName() << std::endl;
    person5.print();

    PersonManager::Child child;
    child.setName("Matei");
    child.setSchool("Scoala Mihai Eminescu");
    child.add("jucaus");
    child.add("energic");
    child.add("mancator de dulciuri");

    // cream un obiect Child folosind copy operator
    PersonManager::Child child1;
    child1 = child;

    std::cout << "Detalii pentru copilul 1: " << child1.getName() << std::endl;
    child1.print();

    PersonManager::Adolescent* adolescent = new PersonManager::Adolescent(18);
    adolescent->setName("Ana");
    adolescent->setHighSchool("Liceul Tudor Arghezi");

    PersonManager::Adult* adult = new PersonManager::Adult();
    adult->setName("Andrei");
    adult->setJob("inginer constructor");

    // cream un obiect Adult folosind copy operator
    PersonManager::Adult adult1;
    adult1 = *adult;

    std::cout << "Detalii pentru adult 1: " << adult1.getName() << std::endl;
    adult1.print();

    std::cout << "Detalii pentru persoana 4: " << person4.getName() << std::endl;
    person4.print();
 
    std::cout << "\nDetali pentru copilul: " << child.getName() << std::endl;
    child.print();

    std::cout << "Detalii pentru adolescentul: " << adolescent->getName() << std::endl;
    adolescent->print();

    std::cout << "Detalii pentru adultul: " << adult->getName() << std::endl;
    adult->print();

    return 0;
}