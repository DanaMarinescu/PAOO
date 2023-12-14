#include "producer/producer.hpp"
#include "consumer/consumer.hpp"
#include <queue>
#include <mutex>
#include <condition_variable>

int main() {
    // Shared buffer between producers and consumers
    std::shared_ptr<std::queue<std::shared_ptr<ProductManagement::Product>>> buffer = std::make_shared<std::queue<std::shared_ptr<ProductManagement::Product>>>();

    // Mutex for protecting access to shared data (buffer)
    std::mutex mutex;

    // Condition variable for synchronization between producers and consumers
    std::condition_variable cv;

    // Create instances of producers and consumers
    ProductManagement::Producer producer1(1);
    ProductManagement::Producer producer2(2);
    ProductManagement::Consumer consumer1(1);
    ProductManagement::Consumer consumer2(2);

    // Start producers and consumers
    producer1.startProducing(buffer, mutex, cv);
    producer2.startProducing(buffer, mutex, cv);
    consumer1.startConsuming(buffer, mutex, cv);
    consumer2.startConsuming(buffer, mutex, cv);

    // Simulate work for a while
    std::this_thread::sleep_for(std::chrono::seconds(15));

    // Stop producers and consumers
    producer1.stopProducing();
    producer2.stopProducing();
    consumer1.stopConsuming();
    consumer2.stopConsuming();

    return 0;
}
