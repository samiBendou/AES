if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(TestAESHandler TestAESHandler.cpp)

target_link_libraries(TestAESHandler gtest gtest_main)
target_link_libraries(TestAESHandler AESHandler)