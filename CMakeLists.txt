cmake_minimum_required(VERSION 2.8)

########################################
# Project setup
########################################
set(PROJECT_NAME project1)
project(${PROJECT_NAME})
# After project(..) is called the following variables are available:
# * PROJECT_SOURCE_DIR - Top level source directory for the project
# * PROJECT_BINARY_DIR - Full path to build directory for project

########################################
# Set up the compile flags
########################################
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 11)


########################################
# Define include directories
########################################
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

########################################
# Source files
########################################
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

########################################
# Main -- separate executable
########################################
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere (e.g linking to the test executable).

########################################
# Compile source files into a library
########################################
add_library(project1_lib ${SRC_FILES} src/message.cpp include/message.h)

########################################
# Main is separate (e.g. library client)
########################################
add_executable(project1 ${PROJECT_SOURCE_DIR}/src/main.cpp src/message.cpp include/message.h)

########################################
# linking Main against the library
########################################
target_link_libraries(project1 project1_lib)


########################################
# Testing
########################################
# Options. Turn on with 'cmake -Dmyvarname=ON'.
# option(BUILD_TESTS "Build all tests." ON) # Makes boolean 'test' available.

# if (BUILD_TESTS)
# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(./googletest)
# 
enable_testing()
# 
# # Include the gtest library. gtest_SOURCE_DIR is available due to
# # 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# 
########################################
# Test files
########################################
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
# ########################################
# # Unit Tests
# ########################################
add_executable(runUnitTests ${TEST_SRC_FILES})
# 
# ########################################
# # Standard linking to gtest stuff.
# ########################################
target_link_libraries(runUnitTests gtest gtest_main)

########################################
# Extra linking for the project.
########################################
target_link_libraries(runUnitTests project1_lib)

# # This is so you can do 'make test' to see all your tests run, instead of
# # manually running the executable runUnitTests to see those specific tests.
# add_test(UnitTests runUnitTests)
# 
# set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.travis/cmake)
# 
# if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
#   include(CodeCoverage)
#   setup_target_for_coverage(${PROJECT_NAME}_coverage runUnitTests coverage)
# 
#   SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
#   SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
# endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"
# 
# #endif()
