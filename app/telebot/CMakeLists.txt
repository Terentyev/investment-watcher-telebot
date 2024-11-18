cmake_minimum_required(VERSION 3.13)
project(telebot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
set(Boost_USE_MULTITHREADED ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
