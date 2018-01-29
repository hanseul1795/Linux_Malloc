//
// Created by h.shin on 1/29/18.
//

#ifndef MALLOC_ALLOCATEMEMORY_H
#define MALLOC_ALLOCATEMEMORY_H

#include <glob.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

#define ALIGNMENT 4
#define ALIGN(size)   ((((size) + ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

typedef struct s_block t_block;

struct s_block
{
    size_t size;
    t_block* next_block;
    t_block* prev_block;
    void* data;
    bool free;
};

void initlialize_block(t_block* p_b);

t_block* extend_heap(size_t p_size);

t_block* find_block(size_t p_size);

//try_to_fuse is "corrected" version of try_to_'fusion' <- WRONG GRAMMAR!!
t_block* try_to_fuse(t_block* p_b);

void split_block(t_block* p_b, size_t p_size);

//my_malloc is translated version of "void* malloc_perso(size_t size)"
void* my_malloc(size_t p_size);

//my_free is translated version of "void free_perso(void* ptr)"
void my_free(void* p_ptr);

#endif //MALLOC_ALLOCATEMEMORY_H