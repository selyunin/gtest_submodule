[![Build Status](https://travis-ci.org/selyunin/gtest_submodule.svg?branch=master)](https://travis-ci.org/selyunin/gtest_submodule)

# Cmake project with google test as a git submodule  and travis CI pipeline

This is a cmake project which uses [googletest](https://github.com/google/googletest)
as a git submodule, and sets up a [travis-ci](https://travis-ci.org/) pipeline for 
running tests. I was inspired by the projects from the [acknowledgement](#acknowledgement)
section, and at the sime time want improve on that: the goal is to use git submodules 
in order to avoid copying google test in the current repo.

## Directory structure
* [`CMakeLists.txt`](./CMakeLists.txt) cmake project files
* [`include/`](./include) header files (`*.h`)
* [`src/`](./src) source files (`*.cpp`)
* [`test/`](./test) test files  (`*.cpp`)

## Building the project
1. Creating the executables follows standard `cmake` procedure:

    mkdir build
    cd build && cmake ..

2. Compile the code (it will also compile the gtest for the first time):

    make

3. Run executable:

    ./project1

4. Cmake supports `add_test` function, then the tests can be launch 
`make test` or `ctest` commands.

    ./runUnitTests


# [Acknowledgement]
The acknowledgments go to:
* [Gunnar](https://github.com/gujans) and
 [this](https://github.com/gujans/travis-gtest-cmake-example)
 repository, for providing a minimal working example of
 [gtest](https://github.com/google/googletest), 
 [travis-ci](https://travis-ci.org/), and 
 [cmake](https://cmake.org/).  
 
 
* [David Y. Zhang](https://github.com/dmonopoly) and 
[this](https://github.com/dmonopoly/gtest-cmake-example) 
repo. For setting up a repo with 
[gtest](https://github.com/google/googletest) and 
[cmake](https://cmake.org/).


