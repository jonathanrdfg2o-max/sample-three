
#pragma once
#include <functional>
#include <string>

class Task {
public:
    using Callback = std::function<void()>;
    Task(std::string name, int priority, Callback cb);
    void run() const;
    int priority() const;
private:
    std::string m_name;
    int m_priority;
    Callback m_callback;
};
