
#include "Scheduler.hpp"
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    Scheduler scheduler;
    scheduler.start();

    scheduler.submit(Task("Render", 10, [] {
        std::cout << "Rendering frame..." << std::endl;
    }));

    scheduler.submit(Task("PostProcess", 5, [] {
        std::cout << "Post processing..." << std::endl;
    }));

    std::this_thread::sleep_for(std::chrono::seconds(1));
    scheduler.stop();
}
