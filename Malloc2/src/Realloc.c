//
// Created by h.shin on 2/2/18.
//

#include "../include/Realloc.h"

void *reallocate_memory(void *p_address, size_t p_size)
{
    if(!p_address)
        return allocate_memory(p_size);

    if(p_address > first_block_address && p_address < sbrk(0))
    {
        size_t aligned_size = align(p_size);
        t_block* resize_block = (t_block*)((char*) p_address - sizeof(t_block));
        if(resize_block->size >= aligned_size)
        {
            if(resize_block->size - aligned_size >= sizeof(t_block) + sizeof(int))
            {
                for(size_t i = aligned_size; i < resize_block->size; ++i)
                {
                    ((char*)resize_block->data)[i] = 0;
                }
                split_block(resize_block, aligned_size);
            }
        }
        else
        {
            if(resize_block->next_block && resize_block->next_block->free && (resize_block->size + sizeof(t_block) + resize_block->next_block->size) >= aligned_size)
            {
                try_to_fuse(resize_block);
                if(resize_block->size - aligned_size >= (sizeof(t_block) + sizeof(int)))
                    split_block(resize_block, aligned_size);


            }
            else
            {
                t_block* to_reallocate = NULL;
                void* reallocate_data = allocate_memory(aligned_size);
                if(reallocate_data)
                {
                    to_reallocate = (t_block*)((char*)reallocate_data - sizeof(t_block));
                    copy_data(resize_block, to_reallocate);
                    free_memory(p_address);
                    return reallocate_data;
                }
                else
                {
                    return NULL;
                }
            }
        }
        return p_address;
    }
    return NULL;
}