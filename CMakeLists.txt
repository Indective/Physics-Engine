cmake_minimum_required(VERSION 3.16)
project(engine)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_subdirectory(external/raylib)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)

if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} m pthread dl rt X11)
endif()