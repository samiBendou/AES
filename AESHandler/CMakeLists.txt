cmake_minimum_required(VERSION 3.12)
project(AESHandler)

set(CMAKE_CXX_STANDARD 11)

include_directories(lib/NAlgebra/header)

add_subdirectory(lib/NAlgebra)

link_libraries(NAlgebra)

add_library (AESHandler STATIC
        source/AESHandler.cpp header/AESHandler.h
        )


