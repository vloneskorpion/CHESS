cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME GAME)
project(${PROJECT_NAME})

find_package (SFML 2.5 COMPONENTS graphics audio network system REQUIRED)

if(NOT SFML_FOUND)
  message(FATAL_ERROR "SFML couldn't be located!")
endif()

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries (${PROJECT_NAME} PUBLIC sfml-system sfml-graphics sfml-audio sfml-network sfml-window)

