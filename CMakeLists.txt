
cmake_minimum_required(VERSION 3.10)

project(infphyny-framework)


include_directories(include)


add_subdirectory(example) 


add_library(fileutils SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/fileutils/fileutils.cpp)