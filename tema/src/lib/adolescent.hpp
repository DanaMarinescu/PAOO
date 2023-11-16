#include "person.hpp"

namespace PersonManager
{
    // subclasa Adolescent a clasei de baza Person
    class Adolescent : public Person
    {
    public:
        Adolescent(const std::string& name, const std::int16_t& age);
        ~Adolescent() override;
        void print() const override;
        std::string getHighSchool() const;
        std::int16_t getAge() const;

    private:
        std::string highSchool;
        std::int16_t age;
    };
} // namespace PersonManager
