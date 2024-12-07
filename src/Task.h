#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <fstream>

// Struct that is representing "Task" in our todolist which contain
// description of the task and his status. And also pointers to the next and previous
// task in our todolist.

struct Task {
    std::string task_;
    bool completed_;
    std::shared_ptr<Task> next_;
    std::weak_ptr<Task> prev_;

    explicit Task(std::string& task, bool completed = false)
            : task_(std::move(task)), completed_(completed), next_(nullptr), prev_() {}
};