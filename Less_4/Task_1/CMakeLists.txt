cmake_minimum_required(VERSION 3.19)
project(Task_1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./catch2)
add_executable(Task_1 main.cpp list.cpp list.h node.h)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)