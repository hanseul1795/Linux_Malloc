//
// Created by h.shin on 2/2/18.
//

#include "../include/Free.h"

void free_memory(void* p_address)
{
    if (!p_address)
        return;

    t_block* temp = NULL;
    t_block* free_manager = NULL;
    if(first_block_address)
    {
        if (p_address > first_block_address && p_address < sbrk(0))
        {
            free_manager = (t_block*)((char*) p_address - sizeof(t_block));
            temp = free_manager;
            free_manager->free = true;
            if (free_manager->prev_block && free_manager->prev_block->free)
            {
                free_manager = try_to_fuse(free_manager->prev_block);
            }
            if (free_manager->next_block)
            {
                try_to_fuse(free_manager);
            }
            reset_memory(p_address, temp->size);
        }
    }
}