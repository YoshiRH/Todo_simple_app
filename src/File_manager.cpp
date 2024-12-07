#include "File_manager.h"

// Passing location of save file
File_manager::File_manager(std::string &&filename)
:filename_(std::move(filename)){

}

// Saving data to file (has to be passed vector with tasks from todolist)
void File_manager::saveToFile(const std::vector<std::pair<std::string, bool>> &data) const {
    std::ofstream file(filename_);
    if (!file) {
        throw std::ios_base::failure("Could'nt open the file");
    }
    for (const auto& [task, completed] : data) {
        file << task << ";" << completed << "\n"; // Pushing tasks and their status to file
    }
}

// Loading data from save file and returning it in vector of pairs of task name and his status
std::vector<std::pair<std::string, bool>> File_manager::loadFromFile() const {
    std::ifstream file(filename_);
    if (!file) {
        // File can still not exist, return empty vector
        return {};
    }

    std::vector<std::pair<std::string, bool>> data; // vector for data from file
    std::string line;
    while (std::getline(file, line)) {
        auto pos = line.find(';');
        if (pos != std::string::npos) {
            std::string task = line.substr(0, pos);
            bool completed = (line.substr(pos + 1) == "1");
            data.emplace_back(task, completed);
        }
    }
    return data;
}
