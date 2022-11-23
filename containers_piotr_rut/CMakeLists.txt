cmake_minimum_required(VERSION 3.13)

project(boost_containers)
set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/Boost")
add_executable(main.exe main.cpp)
find_package(Boost REQUIRED)

