#ifndef CONSUMER_HPP
#define CONSUMER_HPP

#include <memory>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "../product/product.hpp"

namespace ProductManagement {

    class Consumer {
    public:
        explicit Consumer(int id);

        // Start consuming products in a separate thread
        void startConsuming(std::shared_ptr<std::queue<std::shared_ptr<Product>>> buffer,
                            std::mutex& mutex, std::condition_variable& cv);

        // Stop consuming
        void stopConsuming();

    private:
        int id;
        std::thread consumerThread;
        std::atomic<bool> isConsuming; // Used to gracefully stop the consumer
    };

} // namespace ProductManagement

#endif
