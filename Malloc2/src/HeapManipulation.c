//
// Created by h.shin on 2/2/18.
//

#include "../include/HeapManipulation.h"

t_block* extend_heap(size_t p_size)
{
    if(p_size == 0)
        return NULL;

    t_block* temp = NULL;
    temp = (t_block*)sbrk(0);
    if(sbrk(p_size + sizeof(t_block)) == (void*) -1)
        return NULL;

    initialize_block(temp);
    temp->size = p_size;
    temp->data = temp + 1;
    return temp;
}