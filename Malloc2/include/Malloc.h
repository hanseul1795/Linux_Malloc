//
// Created by h.shin on 1/30/18.
//

#ifndef MALLOC_MALLOC_H
#define MALLOC_MALLOC_H

#include <stdbool.h>
#include <stdlib.h>
#include <zconf.h>
#include "AuxFunctions.h"

typedef struct s_block t_block;

struct s_block
{
    size_t size;
    t_block* next_block;
    t_block* prev_block;
    void* data;
    bool free;
};

t_block* extend_heap(size_t p_size);

//Malloc_perso and free_perso
void* allocate_memory(size_t p_size);
void free_memory(void *p_address);

void initialize_block(t_block* p_block);
t_block* find_block(size_t p_size);
void split_block(t_block* p_block, size_t p_size);

//try_to_fusion! Bad English! corrected to try_to_fuse
t_block* try_to_fuse(t_block* p_block);
#endif //MALLOC_MALLOC_H
