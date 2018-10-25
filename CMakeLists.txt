cmake_minimum_required(VERSION 3.12)
project(AESTest)

set(CMAKE_CXX_STANDARD 11)

include_directories(AESHandler/lib/NAlgebra/header)
include_directories(AESHandler/header)

add_subdirectory(AESHandler)
add_subdirectory(TestAES)

add_executable(AES main.cpp)

target_link_libraries(AES AESHandler)