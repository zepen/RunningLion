cmake_minimum_required(VERSION 3.17)
project (RunningLion)

set (CMAKE_CXX_STANDARD 11)
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (SOURCE_DIR             ${PROJECT_SOURCE_DIR}/src)
# set (LIBRARY_OUTPUT_PATH    ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory (src)
add_executable(main main.cpp)
