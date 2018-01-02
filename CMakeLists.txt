cmake_minimum_required(VERSION 3.14)

# set the project name
project(nl-cli)

# set the standarts
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# get cpp files
file(GLOB CPPFILES *.cpp)

# add those files to compile
add_executable(nl-cli ${CPPFILES})