cmake_minimum_required(VERSION 3.9)
project(Malloc C)

set(CMAKE_C_STANDARD 99)

add_executable(Malloc main.c include/AllocateMemory.h src/AllocateMemory.c)