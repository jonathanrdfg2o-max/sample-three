
#include "Scheduler.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    Scheduler scheduler;
    scheduler.start();

    scheduler.submit(Task("Render Job", 10, [] {
        std::cout << "Rendering frame..." << std::endl;
    }));

    scheduler.submit(Task("Cleanup", 1, [] {
        std::cout << "Cleanup job" << std::endl;
    }));

    std::this_thread::sleep_for(std::chrono::seconds(1));
    scheduler.stop();
}
