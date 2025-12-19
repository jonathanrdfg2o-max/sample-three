
#include "Scheduler.hpp"

Scheduler::Scheduler() = default;
Scheduler::~Scheduler(){ stop(); }

void Scheduler::start() {
    m_running = true;
    m_thread = std::thread(&Scheduler::worker, this);
}

void Scheduler::stop() {
    if (!m_running) return;
    m_running = false;
    m_cv.notify_all();
    if (m_thread.joinable()) m_thread.join();
}

void Scheduler::submit(Task task) {
    {
        std::lock_guard lock(m_mutex);
        m_queue.push(std::move(task));
    }
    m_cv.notify_one();
}

void Scheduler::worker() {
    while (m_running) {
        std::unique_lock lock(m_mutex);
        m_cv.wait(lock, [&] { return !m_queue.empty() || !m_running; });
        if (!m_running) break;
        Task task = m_queue.top();
        m_queue.pop();
        lock.unlock();
        task.run();
    }
}
