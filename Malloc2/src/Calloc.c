//
// Created by h.shin on 2/2/18.
//

#include "../include/Calloc.h"

void* c_allocate_memory(size_t p_items, size_t p_size)
{
    if(p_items == 0 || p_size == 0)
        return NULL;

    void* temp = NULL;
    temp = allocate_memory(p_items * p_size);
    if(temp)
    {
        size_t align_size = align(p_items * p_size);
        reset_memory(temp, align_size);
        return temp;
    }
    return NULL;
}