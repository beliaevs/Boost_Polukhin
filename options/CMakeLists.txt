cmake_minimum_required(VERSION 3.8)

project(options)

set(BOOST_ROOT "C:/Boost")
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS program_options)
add_executable(options main.cpp)
target_include_directories(options PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(options Boost::dynamic_linking ${Boost_LIBRARIES})
