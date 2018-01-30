cmake_minimum_required(VERSION 3.9)
project(malloc C)

set(CMAKE_C_STANDARD 99)

add_executable(malloc main.c include/Malloc.h src/Malloc.c)