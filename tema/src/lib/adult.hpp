#ifndef ADULT_HPP
#define ADULT_HPP

#include "person.hpp"

namespace PersonManager
{
    // subclasa Adult a clasei de baza Person
    class Adult : public Person
    {
    public:
        Adult();
        ~Adult() override;
        void print() const override;
        std::string getJob() const;
        void setJob(const std::string &job);

    private:
        std::string job;
    };

} // namespace PersonManager

#endif