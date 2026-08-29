cmake_minimum_required(VERSION 3.16)

project(oop_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(vehicles examples/cpp/inheritance/vehicles.cpp)
add_executable(people examples/cpp/inheritance/people.cpp)

if(MSVC)
    target_compile_options(vehicles PRIVATE /W4 /permissive-)
    target_compile_options(people PRIVATE /W4 /permissive-)
else()
    target_compile_options(vehicles PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(people PRIVATE -Wall -Wextra -Wpedantic)
endif()
