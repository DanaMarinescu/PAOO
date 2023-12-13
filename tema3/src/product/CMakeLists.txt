add_library(productLib product.cpp foodProduct.cpp)

target_include_directories(productLib PUBLIC 
                        "${PROJECT_BINARY_DIR}/product")
                        