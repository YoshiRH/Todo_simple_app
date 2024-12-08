# Todo Simple App

A simple console-based Todo app with save and load functionality.

## Features
- Add, view, and delete tasks.
- Save your tasks to a file.
- Load tasks from a file to continue where you left off.

## How to Run

### 1. Using File Explorer
1. Clone or download the repository and extract it to a desired location.
2. Navigate to the folder where the program is located.
3. Open the `cmake-build-debug` directory.
4. Double-click `Todo_simple_app.exe` to run the application.

### 2. Using PowerShell or Command Prompt
1. Navigate to the folder where the program is located cd {path_to_program},
2. cd "cmake-build-debug"
3. ./Todo_simple_app.exe

## Requirements
- Windows operating system.
- C++ compiler (if you plan to compile the project yourself, e.g., G++ or MSVC).

## Building from Source
1. Ensure you have CMake and a C++ compiler installed on your system.
2. Clone the repository: git clone https://github.com/YoshiRH/Todo_simple_app.git
3. Navigate to the project folder: cd Todo_simple_app
4. Create a build directory and navigate into it: mkdir build && cd build
5. Generate build files using CMake: cmake ..
6. Build the project: cmake --build .
7. Run the application: ./Todo_simple_app.exe
