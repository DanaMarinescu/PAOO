add_library(consumerLib consumer.cpp)

target_link_libraries(consumerLib PUBLIC productLib)

target_include_directories(consumerLib PUBLIC
                            "${PROJECT_BINARY_DIR}/product")