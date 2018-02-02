cmake_minimum_required(VERSION 3.9)
project(Malloc2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Malloc2
        include/Malloc.h
        include/MemsetAlign.h
        include/BlockVariable.h
        src/main.c
        src/Malloc.c
        src/MemsetAlign.c
        src/BlockVariable.c src/BlockManipulation.c include/BlockManipulation.h src/HeapManipulation.c include/HeapManipulation.h src/Free.c include/Free.h include/MemoryManagement.h src/Realloc.c include/Realloc.h src/Calloc.c include/Calloc.h)

target_link_libraries(Malloc2 m)
