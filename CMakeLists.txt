
cmake_minimum_required(VERSION 3.16)
project(TaskScheduler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_scheduler
    src/main.cpp
    src/Scheduler.cpp
    src/Task.cpp
)

target_include_directories(task_scheduler PRIVATE include)
