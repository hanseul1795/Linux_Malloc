//
// Created by h.shin on 2/1/18.
//

#include "../include/MemsetAlign.h"
size_t align(size_t p_size)
{
    if(p_size == 0)
        return 0;

    return ((p_size + (sizeof(size_t) - 1)) & ~(sizeof(size_t) - 1));
}

void reset_memory(void* p_address, size_t p_size)
{
    for (size_t i = 0; i * sizeof(size_t)< (p_size); ++i)
    {
        ((size_t*)p_address)[i] = 0;
    }
}