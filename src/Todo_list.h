#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Task.h"
#include "File_manager.h"

// Main function with todolist, implemented functions to add, remove,
// change status and also remove the task from the list.
// The whole structure of that works like a double-linked-list where
// every element in connected to the next and previous object if that exist.

class Todo_list {
public:
    // Constructor, have to be passed string with save file location
    // thanks to that, opening and closing file is automatic
    explicit Todo_list(std::string&& filename);

    ~Todo_list();

    void add(std::string task); // Argument: string which is a description of the task we want to add
    void printTasks() const; // Printing every task in list
    void toggleComplete(int index); // Change status (bool) of the task with passed index
    void remove(int index); // Remove task with passed index

private:
    std::shared_ptr<Task> head_ = nullptr; // Beginning of the list
    std::shared_ptr<Task> tail_ = nullptr; // End of the list
    File_manager fileManager_; // Instance of fileManager which take care of saving&loading from file

    std::shared_ptr<Task> getTaskByIndex(int index) const; // Return the task object with passed index

    void saveToFile() const; // Saving list
    void loadFromFile(); // Loading list from file
};
