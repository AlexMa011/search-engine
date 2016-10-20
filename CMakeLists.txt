cmake_minimum_required(VERSION 3.6)
project(search-engine)

find_package(Boost)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/Projects/search-engine")
add_subdirectory(src)

