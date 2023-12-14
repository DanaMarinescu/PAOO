#include "foodProduct.hpp"
#include <iostream>

namespace ProductManagement {

    FoodProduct::FoodProduct(const std::string& name, const std::string& expirationDate)
        : Product(name), expirationDate(expirationDate) {}

    void FoodProduct::displayInfo() const {
        std::cout << "Food Product: " << name << ", Expiration Date: " << expirationDate << std::endl;
    }

} // namespace ProductManagement
