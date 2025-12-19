
#include "Scheduler.hpp"
#include <iostream>

int main() {
    Scheduler scheduler;
    scheduler.start();

    scheduler.submit(Task("High Priority", 10, [] {
        std::cout << "Executing high priority task" << std::endl;
    }));

    scheduler.submit(Task("Low Priority", 1, [] {
        std::cout << "Executing low priority task" << std::endl;
    }));

    std::this_thread::sleep_for(std::chrono::seconds(1));
    scheduler.stop();
}
