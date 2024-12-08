#include <iostream>

#include "src/Todo_list.h"

using std::cout;
using std::cin;

int main() {
    // Creating todolist object and passing it's save location
    Todo_list todoList("../save/todo.txt");
    int choice;

    do {
        // Just print user menu at each loop
        cout << "\nMenu:\n";
        cout << "1. Create new task\n";
        cout << "2. Print my tasks\n";
        cout << "3. Change status of task\n";
        cout << "4. Delete task\n";
        cout << "0. Save&Exit\n";
        cout << "Enter: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear the buffor
                std::string task;
                cout << "Describe your task: ";
                std::getline(std::cin, task); // Using getline to also catch spaces
                todoList.add(task); // Function that create task with description from user
                                    // in our todolist
                break;
            }
            case 2:
                cout << "\nMy Tasks:\n";
                todoList.printTasks(); // Function that print every task in todolist obiect
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task that you want to change status: ";
                cin >> index;
                todoList.toggleComplete(index); // Function that reverse bool (status) of
                                                // the task with the entered index
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                todoList.remove(index); // Function that remove task obiect from todolist
                break;
            }
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Wrong entry, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
