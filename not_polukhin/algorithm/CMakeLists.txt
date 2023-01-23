cmake_minimum_required(VERSION 3.20)

project(algorithm)
set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/Boost")
add_executable(algorithm main.cpp)
find_package(Boost REQUIRED)
target_include_directories(algorithm PUBLIC ${Boost_INCLUDE_DIRS})
