cmake_minimum_required(VERSION 3.8)

project(any_variant)
set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/Boost")
add_executable(any_variant main.cpp)
find_package(Boost REQUIRED)
target_include_directories(any_variant PUBLIC ${Boost_INCLUDE_DIRS})
