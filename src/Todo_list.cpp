#include "Todo_list.h"

// Constructor, while creating instance, automatically loading saved list from save file
Todo_list::Todo_list(std::string &&filename)
: fileManager_(std::move(filename)){
    loadFromFile();
}

// Destructor, saving list to file at the end of the program
Todo_list::~Todo_list() {
    saveToFile();
}

// Add task to the todolist
void Todo_list::add(std::string task) {
    // Shared pointer for a task we want to add
    auto new_task = std::make_shared<Task>(task);
    if (!head_) {
        head_ = tail_ = new_task; // Checking if there is any task in list
    } else {
        tail_->next_ = new_task; // Inserting task at the end of the list
        new_task->prev_ = tail_;
        tail_ = new_task; // Setting inserted task as the last in our todolist
    }
}

// Print every task in the todolist
void Todo_list::printTasks() const {
    auto current = head_;
    int index = 1;
    while (current) { // While current is not nullptr = checking if there is a task in list
        std::cout << index++ << ". ["
                  << (current->completed_ ? "x" : " ") << "] "
                  << current->task_ << "\n";
        current = current->next_;
    }
}

// Change status of the task with passed index
void Todo_list::toggleComplete(int index) {
    auto task = getTaskByIndex(index); // return task with passed index
    if (task) { // Check if task exist
        task->completed_ = !task->completed_; // Reverse status (bool)
        std::cout << "Changed status as: "
                  << (task->completed_ ? "Completed" : "Ongoing") << "\n";
    } else {
        std::cout << "Could'nt find a task with that index.\n";
    }
}

// Removing task with passed index
void Todo_list::remove(int index) {
    auto task = getTaskByIndex(index); // return task with passed index
    if (task) { // Check if task exist
        auto prev = task->prev_.lock();
        auto next = task->next_;

        if (prev) prev->next_ = next;
        if (next) next->prev_ = prev;

        if (task == head_) head_ = next;
        if (task == tail_) tail_ = prev;

        std::cout << "Task deleted: " << task->task_ << "\n";
        // Operations that changing adjacent task to point at each other and not
        // at the task which we want to delete, we are 'skipping' that task, and
        // thanks to that, no more object point at the task which we want to delete
        // so the shared_ptr->count = 0, and task is deleted
    } else {
        std::cout << "Could'nt find a task with that index.\n";
    }
}

// Returns the task from todolist with passed index
std::shared_ptr<Task> Todo_list::getTaskByIndex(int index) const {
    auto current = head_;
    int currentIndex = 1;
    while (current) { // Looping through the list until we find a task with passed index
        if (currentIndex == index) {
            return current; // returning task with passed index
        }
        current = current->next_;
        ++currentIndex;
    }
    return nullptr; // If we could'nt find task with passed index, return nullptr
}

// Saving todolist to the file
void Todo_list::saveToFile() const {
    std::vector<std::pair<std::string, bool>> data; // Vector pair with task name and his status
    auto current = head_;
    while (current) { // pushing every task to vector
        data.emplace_back(current->task_, current->completed_);
        current = current->next_;
    }

    try {
        fileManager_.saveToFile(data); // sending vector with all tasks to fileManager
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Exception at saving to file: " << e.what() << '\n';
    }
}

// Loading tasks from the file
void Todo_list::loadFromFile() {
    auto data = fileManager_.loadFromFile(); // return vector pair with task name and his status
                                                                  // loaded from save file
    for (const auto& [task, completed] : data) {
        add(task); // Pushing loaded tasks back to the todolist
        tail_->completed_ = completed; // Update status of that task
    }
}
