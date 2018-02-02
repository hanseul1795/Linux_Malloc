//
// Created by h.shin on 2/2/18.
//

#include "../include/BlockManipulation.h"

void initialize_block(t_block* p_block)
{
    if(!p_block)
        return;

    p_block->prev_block = NULL;
    p_block->next_block = NULL;
    p_block->size = 0;
    p_block->data = 0;
    p_block->free = false;
}

t_block *find_block(size_t p_size)
{
    t_block* temp = (t_block*)first_block_address;
    while(temp)
    {
        if(temp->free && temp->size >= p_size)
        {
            return temp;
        }
        temp = temp->next_block;
    }
    return NULL;
}

void split_block(t_block *p_block, size_t p_size)
{
    if(!p_block || p_size == 0)
        return;

    t_block* to_split = NULL;
    to_split = (t_block*)((char*)p_block->data + p_size);
    to_split->size = p_block->size - p_size - sizeof(t_block);
    to_split->next_block = p_block->next_block;
    to_split->prev_block = p_block;
    to_split->free = true;
    to_split->data = to_split + 1;
    p_block->size = p_size;
    p_block->next_block = to_split;

    if(to_split->next_block)
        to_split->next_block->prev_block = to_split;
}

t_block* try_to_fuse(t_block *p_block)
{
    if(!p_block)
        return NULL;

    if(p_block->next_block && p_block->next_block->free)
    {
        p_block->size += sizeof(t_block) + p_block->next_block->size;
        p_block->next_block = p_block->next_block->next_block;
        if(p_block->next_block)
            p_block->next_block->prev_block = p_block;
    }
    return p_block;
}

void copy_data(t_block *p_src, t_block *p_dest)
{
    if(!p_src || !p_dest)
        return;

    reset_memory(p_dest->data, p_dest->size);
    char* src = (char*)p_src->data;
    char* dest = (char*)p_dest->data;
    if(p_src->size >= p_dest->size)
    {
        for(size_t i = 0; i < p_dest->size; ++i)
        {
            dest[i] = src[i];
        }
    }
    else if(p_src->size < p_dest->size)
    {
        for(size_t i = 0; i < p_src->size; ++i)
        {
            dest[i] = src[i];
        }
    }
}