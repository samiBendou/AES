cmake_minimum_required(VERSION 3.12)
project(AESHandler)

set(CMAKE_CXX_STANDARD 11)

add_library (AESHandler STATIC
        ../NAlgebra/source/AESByte.cpp ../NAlgebra/header/AESByte.h
        source/AESHandler.cpp header/AESHandler.h
        source/ByteMatrix.cpp header/ByteMatrix.h
        )
