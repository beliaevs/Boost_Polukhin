cmake_minimum_required(VERSION 3.13)

project(base_from_member)
set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/Boost")
add_executable(main main.cpp)
find_package(Boost REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )