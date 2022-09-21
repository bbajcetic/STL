## Basic reimplementation of the C++ Standard Template Library (STL) to learn C++ better: 

STL is made up of:
    -Containers
    -Iterators
    -Algorithms

I'm starting with the container classes and will implement iterators and algorithms afterwards

***

## To build the project:

Using Google Test as a testing library to test the classes, and CMake as a build system generator

1) Create a build folder:
    `$ mkdir build && cd build`

2) Build the project:
    `$ cmake .. && cmake --build .`

3) Run the tests:
    `$ cd tests/<class>/ && ./<executable_file>`
        OR
    `$ ctest`
