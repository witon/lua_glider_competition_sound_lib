include(GoogleTest)
cmake_minimum_required(VERSION 3.13)

#project(lua_glider_competition_sound_lib_test)
if(WIN32)
    SET(TEST_SRC test.cpp ../win_com.cpp test_win_com.cpp ../pandora_wrap.cpp test_pandora_wrap.cpp)
    set(CMAKE_CXX_COMPILER "g++")
    set(GTEST_INCLUDE_DIR "C:/Program Files (x86)/googletest-distribution/include/")
    set(GTEST_LIB_DIR "C:/Program Files (x86)/googletest-distribution/lib/")
    enable_testing()
    ADD_EXECUTABLE(test ${TEST_SRC})
    target_include_directories(test PRIVATE ${GTEST_INCLUDE_DIR})
    target_link_directories(test PRIVATE ${GTEST_LIB_DIR})
    target_link_libraries(test gtest)
    add_test(NAME test COMMAND test.exe)
    #gtest_discover_tests(test1)
endif(WIN32)
if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()
if(LINUX)
    SET(TEST_SRC test.cpp ../linux_com.cpp test_linux_com.cpp ../pandora_wrap.cpp)
    set(CMAKE_CXX_COMPILER "g++")
    find_package(GTest REQUIRED)
    enable_testing()
    ADD_EXECUTABLE(linux_test ${TEST_SRC})
    target_include_directories(linux_test PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(linux_test ${GTEST_LIBRARIES} pthread)
    add_test(NAME test COMMAND test.exe)
    #gtest_discover_tests(test1)

endif(LINUX)
