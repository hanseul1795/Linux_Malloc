//
// Created by h.shin on 2/2/18.
//

#ifndef MALLOC2_BLOCKMANIPULATION_H
#define MALLOC2_BLOCKMANIPULATION_H
#include "BlockVariable.h"
#include "MemsetAlign.h"
void initialize_block(t_block* p_block);

t_block* find_block(size_t p_size);

void split_block(t_block* p_block, size_t p_size);

void copy_data(t_block* p_src, t_block* p_dest);

//try_to_fusion! Bad English! corrected to try_to_fuse
t_block* try_to_fuse(t_block* p_block);

#endif //MALLOC2_BLOCKMANIPULATION_H