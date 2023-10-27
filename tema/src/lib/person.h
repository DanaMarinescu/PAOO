#include <string>

class Person {
    public:
    //in lista de parametrii ai constructorului, punem ca argument catre constructor o referinta la un obiect constant
    //(const right value reference)
        Person(const std::string& name);
        void setName(const std::string& name);
        std::string getName() const; 

    //destructor
        ~Person();

    //copy constructor ce implica deep copy
        Person(const Person& person);
    
    //move constructor ce implica shallow copy
        Person(Person&& person);

    private:
        std::string name;
};

