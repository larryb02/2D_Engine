cmake_minimum_required(VERSION 3.10)
project(2D_Engine)

#download dependencies
# if(find_package())

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SRC_DIR "src")
file(GLOB_RECURSE SRC_FILES
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/*.c"
    "include/stb_image/*.cpp"
)
set(INCLUDE_PATHS include include/SDL2)
set(LIBRARY_PATHS "lib/SDL2") #a hack
set(COMPILER_FLAGS -Wall -g)

message(STATUS "Source Dir: ${SRC_DIR}")
message(STATUS "Source files found: ${SRC_FILES}")
message(STATUS "Include_Paths: ${INCLUDE_PATHS}")
message(STATUS "Library Paths: ${LIBRARY_PATHS}")
message(STATUS "COMPILER_FLAGS: ${COMPILER_FLAGS}")

include_directories(${INCLUDE_PATHS})
link_directories(${LIBRARY_PATHS})
add_executable(main ${SRC_FILES})
target_compile_options(main PRIVATE ${COMPILER_FLAGS})
target_link_libraries(main PRIVATE SDL2)
