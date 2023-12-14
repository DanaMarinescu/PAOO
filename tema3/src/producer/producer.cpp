#include "producer.hpp"
#include <chrono>

namespace ProductManagement {

    Producer::Producer(int id) : id(id), isProducing(false) {}

    void Producer::startProducing(std::shared_ptr<std::queue<std::shared_ptr<Product>>> buffer,
                                  std::mutex& mutex, std::condition_variable& cv) {
        isProducing = true;

        producerThread = std::thread([this, buffer, &mutex, &cv]() {
            while (isProducing) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                std::shared_ptr<Product> product;
                product = std::make_shared<FoodProduct>("Food: " + std::to_string(id), "28.01.2024");
                
                std::lock_guard<std::mutex> lock(mutex);
                buffer->push(product);
                std::cout << "Produced: ";
                product->displayInfo();
                
                std::cout << "Finished producer thread!" <<std::endl;

                cv.notify_one();
            }
        });
    }

    void Producer::stopProducing() {
        isProducing = false;
        if (producerThread.joinable()) {
            producerThread.join();
        }
    }

} // namespace ProductManagement
