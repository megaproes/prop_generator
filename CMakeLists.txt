cmake_minimum_required(VERSION 3.26)
project(Task1)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXE_LINKER_FLAGS "-static")


include_directories(${CMAKE_SOURCE_DIR}/include)
# set(SOURCESS
#     source/main.cpp
#     source/ReportGenerator.cpp
#     source/TxtReportGenerator.cpp
#     source/JsonReportGenerator.cpp
#     source/ReportFactory.cpp
#     source/DirectoryReader.cpp
#     source/XmlReportGenerator.cpp
#     source/CsvReportGenerator.cpp
#     include/pugixml-master/pugixml.cpp
# )
file(GLOB_RECURSE  sources
    "${CMAKE_SOURCE_DIR}/source/*.cpp"
    "${CMAKE_SOURCE_DIR}/include/pugixml-master/pugixml.cpp")
    
add_executable(Task1 ${sources})
