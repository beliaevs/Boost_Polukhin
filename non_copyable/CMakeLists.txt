cmake_minimum_required(VERSION 3.13)

project(non_copyable)
set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/Boost")
add_executable(main main.cpp myclass.h)
find_package(Boost REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )