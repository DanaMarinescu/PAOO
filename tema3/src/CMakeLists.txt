cmake_minimum_required(VERSION 3.10)

project(ProductManagementApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(producer)
add_subdirectory(product)
add_subdirectory(consumer)

add_executable(ProductManagementApp main.cpp)

target_link_libraries(ProductManagementApp PUBLIC producerLib productLib consumerLib)

target_include_directories(ProductManagementApp PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/producer/include"
                           "${PROJECT_SOURCE_DIR}/product/include"
                           "${PROJECT_SOURCE_DIR}/consumer/include"
                           )