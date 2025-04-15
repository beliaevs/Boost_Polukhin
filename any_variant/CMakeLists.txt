cmake_minimum_required(VERSION 3.28)

project(any_variant CXX)
add_executable(any_variant main.cpp)
target_compile_features(any_variant PRIVATE cxx_std_17)
set(BOOST_ROOT "C:/Boost")
find_package(Boost REQUIRED NO_MODULE)
target_include_directories(any_variant PUBLIC ${Boost_INCLUDE_DIRS})
