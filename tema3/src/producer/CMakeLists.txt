add_library(producerLib producer.cpp)

target_link_libraries(producerLib PUBLIC productLib)

target_include_directories(producerLib PUBLIC
                            "${PROJECT_BINARY_DIR}/product")