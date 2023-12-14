#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include "../product/product.hpp"
#include "../product/foodProduct.hpp"
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <memory>

namespace ProductManagement {
    class Producer {
        public:
        explicit Producer(int id);

        // Start producing products in a separate thread
        void startProducing(std::shared_ptr<std::queue<std::shared_ptr<Product>>> buffer,
                            std::mutex& mutex, std::condition_variable& cv);

        // Stop producing
        void stopProducing();

    private:
        int id;
        std::thread producerThread;
        std::atomic<bool> isProducing; // Used to gracefully stop the producer
    };

} // namespace ProductManagement

#endif