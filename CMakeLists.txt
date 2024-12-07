cmake_minimum_required(VERSION 3.27)
project(Todo_simple_app VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(Todo_simple_app main.cpp
        src/Task.h
        src/Todo_list.h
        src/Todo_list.cpp
        src/File_manager.h
        src/File_manager.cpp)
