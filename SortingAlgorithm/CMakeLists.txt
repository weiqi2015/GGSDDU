cmake_minimum_required(VERSION 3.0.0)

if(${CMAKE_VERSION} VERSION_LESS 3.24)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif(${CMAKE_VERSION} VERSION_LESS 3.12)

project(Sort VERSION 0.1.0)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(src)

add_executable(Sort src/main.cpp)
target_link_libraries(Sort sort)
target_link_directories(Sort 
                            PRIVATE "${PROJECT_SOURCE_DIR}/bin")
target_include_directories(Sort 
                                PRIVATE "${PROJECT_SOURCE_DIR}/src/sort")
