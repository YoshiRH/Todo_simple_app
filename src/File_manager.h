#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Class that handle for us saving and loading from the file automatically
// the tasks are loaded from file at the beggining of the program and
// saving changes at the end of the program.

class File_manager {
public:
    explicit File_manager(std::string&& filename); // Passing save file location

    // Save to file
    void saveToFile(const std::vector<std::pair<std::string, bool>>& data) const;

    // Load from file
    std::vector<std::pair<std::string, bool>> loadFromFile() const;

private:
    std::string filename_;
};
