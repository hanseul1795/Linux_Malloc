//
// Created by h.shin on 2/2/18.
//

#ifndef MALLOC2_SBLOCKSTRUCT_H
#define MALLOC2_SBLOCKSTRUCT_H

#include <stdbool.h>
#include <glob.h>
#include <stdlib.h>
#include <zconf.h>
#include <math.h>

typedef struct s_block t_block;

struct s_block
{
    size_t size;
    t_block* next_block;
    t_block* prev_block;
    void* data;
    bool free;
};

extern void* first_block_address;
#endif //MALLOC2_SBLOCKSTRUCT_H
