
#include "Task.hpp"
#include <iostream>

Task::Task(std::string name, int priority, Callback cb)
    : m_name(std::move(name)), m_priority(priority), m_callback(std::move(cb)) {}

void Task::run() const {
    std::cout << "[TASK] " << m_name << std::endl;
    m_callback();
}

int Task::priority() const { return m_priority; }
