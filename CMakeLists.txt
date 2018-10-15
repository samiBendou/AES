cmake_minimum_required(VERSION 3.12)
project(AESTest)

set(CMAKE_CXX_STANDARD 11)

include_directories(NAlgebra/header)
include_directories(AESHandler/header)

add_subdirectory(NAlgebra)
add_subdirectory(AESHandler)

add_executable(AESTest main.cpp)

target_link_libraries(AESTest NAlgebra AESHandler)