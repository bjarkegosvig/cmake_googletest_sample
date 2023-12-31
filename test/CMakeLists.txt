cmake_minimum_required(VERSION 3.16)
project(AdditionTest LANGUAGES CXX C)

# Download googletest and make it available for make.
# This step can be separated into a top level CMakeLists.txt which calls multiple tests
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# enable testing and googletest in cmake
enable_testing()
include(GoogleTest)

# Create a test executable 
add_executable(addition_test "")

# Specify source files to the target executable
target_sources(addition_test PRIVATE
    addition_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/add.c
)

# Specify include path directories to the target executable 
target_include_directories(addition_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../inc
)

# Specify libraries used bythe target executable 
target_link_libraries(addition_test
 PRIVATE
  GTest::GTest )

# Add the test which can be discovered by test framework
gtest_discover_tests(addition_test)
