cmake_minimum_required(VERSION 3.10)
project(2D_Engine)

#download dependencies
# if(find_package())

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SRC_FILES)
set(INCLUDE_PATHS)
set(LIBRARY_PATHS)
set(COMPILE_FLAGS "-Wall -g -std=c++17")

include_directories(${INCLUDE_PATHS})
link_directories(${LIBRARY_PATHS})
add_executable(main ${SRC_FILES})
target_compile_options(main PRIVATE ${COMPILE_FLAGS})
