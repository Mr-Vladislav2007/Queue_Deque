cmake_minimum_required(VERSION 3.10)
project(Queue_Deque LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB queue ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(QueueApp ${queue})

target_include_directories(QueueApp PRIVATE include)