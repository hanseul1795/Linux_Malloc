//
// Created by h.shin on 1/30/18.
//

#include "../include/Malloc.h"

void* allocate_memory(size_t p_size)
{
    if(p_size == 0)
        return NULL;

    t_block* prev = NULL;
    t_block* temp = NULL;
    size_t aligned_size = align(p_size);

    if(!first_block_address)
    {
        temp = extend_heap(aligned_size);
        first_block_address = temp;
    }
    else if(first_block_address)
    {
        prev = (t_block*)first_block_address;
        temp = find_block(p_size);
        if(temp)
        {
            if((temp->size - aligned_size) >= (sizeof(t_block) + sizeof(int)))
            {
                split_block(temp, aligned_size);
            }
        }
        else
        {
            while(prev->next_block != NULL)
            {
                prev = prev->next_block;
            }
            temp = extend_heap(aligned_size);
            prev->next_block = temp;
            temp->prev_block = prev;
        }
        temp->free = false;
    }
    return temp->data;
}