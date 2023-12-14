#ifndef FOOD_PRODUCT_HPP
#define FOOD_PRODUCT_HPP

#include "product.hpp"

namespace ProductManagement {

    class FoodProduct : public Product {
    public:
        FoodProduct(const std::string& name, const std::string& expirationDate);
        void displayInfo() const override;

    private:
        std::string expirationDate;
    };

} // namespace ProductManagement

#endif
