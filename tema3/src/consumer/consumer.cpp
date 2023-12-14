#include "consumer.hpp"
#include <chrono>
#include <iostream>

namespace ProductManagement {

    Consumer::Consumer(int id) : id(id), isConsuming(false) {}

    void Consumer::startConsuming(std::shared_ptr<std::queue<std::shared_ptr<Product>>> buffer,
                                  std::mutex& mutex, std::condition_variable& cv) {
        isConsuming = true;

        consumerThread = std::thread([this, buffer, &mutex, &cv]() {
            while (isConsuming) {
                std::unique_lock<std::mutex> lock(mutex);
                cv.wait(lock, [buffer]() { return !buffer->empty(); });

                std::shared_ptr<Product> product = buffer->front();
                buffer->pop();
                lock.unlock();

                std::cout << "Consumed: ";
                product->displayInfo();
                
                std::cout << "Finished consumer thread!" << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                
            }
        });
    }

    void Consumer::stopConsuming() {
        isConsuming = false;
        if (consumerThread.joinable()) {
            consumerThread.join();
        }
    }

} // namespace ProductManagement
