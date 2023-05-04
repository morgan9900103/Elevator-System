cmake_minimum_required(VERSION 2.6)
project(elevator)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(elevator ${SOURCES})

set_property(TARGET elevator PROPERTY CXX_STANDARD 17)
target_compile_options(elevator PRIVATE -Wall -Wextra)

