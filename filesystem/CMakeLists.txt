cmake_minimum_required(VERSION 3.8)

project(filesystem)

set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/Boost")
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS system filesystem)
add_executable(filesystem main.cpp)
target_link_libraries(filesystem Boost::dynamic_linking ${Boost_LIBRARIES})
