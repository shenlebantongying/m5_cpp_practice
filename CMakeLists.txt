cmake_minimum_required(VERSION 3.17)
project(m5)

set(CMAKE_CXX_STANDARD 17)

add_executable(m5 main.cpp)

add_custom_command(
    TARGET m5 PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/template.txt  ${CMAKE_CURRENT_BINARY_DIR}/template.txt
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/substitution.txt  ${CMAKE_CURRENT_BINARY_DIR}/substitution.txt)
