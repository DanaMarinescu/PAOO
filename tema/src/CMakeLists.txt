cmake_minimum_required(VERSION 3.10)

project(PersonApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

add_executable(PersonApp main.cpp)

target_link_libraries(PersonApp PUBLIC lib)

target_include_directories(PersonApp PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/lib"
                           )
