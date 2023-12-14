#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

namespace ProductManagement {

    class Product {
    public:
        Product(const std::string& name);
        virtual ~Product() = default;
        virtual void displayInfo() const = 0;

    protected:
        std::string name;
    };

} // namespace ProductManagement

#endif
