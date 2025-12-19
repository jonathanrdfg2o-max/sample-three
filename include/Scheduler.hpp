
#pragma once
#include "Task.hpp"
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>

class Scheduler {
public:
    Scheduler();
    ~Scheduler();
    void start();
    void stop();
    void submit(Task task);
private:
    void worker();
    struct TaskCompare {
        bool operator()(const Task& a, const Task& b) const {
            return a.priority() < b.priority();
        }
    };
    std::priority_queue<Task, std::vector<Task>, TaskCompare> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::thread m_thread;
    std::atomic<bool> m_running{false};
};
