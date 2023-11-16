#include "person.hpp"

namespace PersonManager
{
    // subclasa Adult a clasei de baza Person
    class Adult : public Person
    {
    public:
        ~Adult() override;
        void print() const override;
        std::string getJob() const;

    private:
        std::string job;
    };

} // namespace PersonManager
