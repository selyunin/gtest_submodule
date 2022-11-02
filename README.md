# Cmake + googletest (git submodule) + Github actions

A toy project showcasing the following features:
* [`cmake`](https://cmake.org/) build for C++ project source files;
* [`googletest`](https://github.com/google/googletest) 
  as a [`git submodule`](https://git-scm.com/book/en/v2/Git-Tools-Submodules);
* [`github-actions`](https://docs.github.com/en/actions) pipeline for running build and tests. 

In short, you see a C++ project that uses google test as a 
git submodule and integrates a Github CI pipeline 
(which in Github-terms is called Github actions).

Initially the pipeline run on travis CI. 
In October 2022 I updated the repo to use Github Actions instead.

I was inspired by the projects from the [acknowledgement](#acknowledgement)
section, and at the sime time want improve on that: the goal is to use 
git submodules in order to avoid copying google test in the current repo.

## Directory structure
* [`CMakeLists.txt`](./CMakeLists.txt) cmake project files
* [`include/`](./include) header files (`*.h`)
* [`src/`](./src) source files (`*.cpp`)
* [`test/`](./test) test files  (`*.cpp`)

## Cloning the project
Use `git clone --recursive ...` to download the project and its git submodules.
Otherwise from the project root repository one needs to download the submodules: 
`git submodule update --init`.

## Building the project
1. Creating the executables follows standard `cmake` procedure:
```
cmake -B build
```

2. Compile the code (it will also compile the gtest for the first time):
```
cmake --build build
```

3. Run executable:
```
./build/project1
```

4. Cmake supports `add_test` function, then the tests can be launch 
`make test` or `ctest` commands.
```
./build/runUnitTests
```

alternatively, in the `build` directory, run:
```
ctest
```

## Acknowledgement
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


## Maintainer

[Dr. Konstantin Selyunin](https://selyunin.github.io/), for
suggestions/questions/comments please contact: selyunin [dot] k [dot] v [at] gmail [dot] com
