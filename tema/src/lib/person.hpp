#include <string>

class Person {
    public:
    //constructor default
        Person();
        
    //functii specifice pentru clasa 'Person'
        void setName(const std::string& name);
        std::string getName() const; 
        void print() const;
        void add(const char* detail);

    //destructor
        ~Person();

    //copy constructor ce implica deep copy
        Person(const Person& person);
    
    //move constructor ce implica shallow copy
        Person(Person&& person);

    private:
        std::string name;
        char** array;
        int size;
        int capacity;
};

