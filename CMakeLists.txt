cmake_minimum_required(VERSION 3.26)
project(Task1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)
# Пути к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB sources
    "${CMAKE_SOURCE_DIR}/source/*.cpp"
    "${CMAKE_SOURCE_DIR}/include/pugixml-master/pugixml.cpp")
add_executable(Task1 ${sources})
