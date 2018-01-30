//
// Created by h.shin on 1/30/18.
//
#include <zconf.h>
#include <string.h>
#include "../include/Malloc.h"
void* first_block_address = NULL;

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

void* allocate_memory(size_t p_size)
{
    if(p_size == 0)
        return NULL;

    t_block* prev;
    t_block* temp;
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
            if((temp->size - aligned_size) >= (sizeof(t_block) + 4))
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

size_t align(size_t p_size)
{
    return (p_size + (sizeof(size_t) - 1)) & ~(sizeof(size_t) - 1);
}

t_block *find_block(size_t p_size)
{
    t_block* temp = (t_block*)first_block_address;
    while(temp)
    {
        temp = temp->next_block;
        if(temp && temp->free && temp->size >= p_size)
        {
            return temp;
        }
    }
    return NULL;
}

void split_block(t_block *p_block, size_t p_size)
{
    if(!p_block || p_size == 0)
        return;

    t_block* to_split;
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

t_block *try_to_fuse(t_block *p_block)
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

void free_memory(void *p_address)
{
    if (!p_address)
        return;

    t_block *free_manager;
    if(first_block_address)
    {
        if(p_address > first_block_address && p_address < sbrk(0))
        {
            free_manager = (t_block*)((char*)p_address - sizeof(t_block));
            free_manager->free = true;
            if (free_manager->prev_block && free_manager->prev_block->free)
            {
                free_manager = try_to_fuse(free_manager->prev_block);
                memset(free_manager + 1, 0, free_manager->size);
            }
            if (free_manager->next_block)
            {
                try_to_fuse(free_manager);
                memset(free_manager + 1, 0, free_manager->size);
            }
            else
            {
                if (free_manager->prev_block)
                {
                    free_manager->prev_block->next_block = NULL;
                }
                memset(free_manager + 1, 0, free_manager->size);
                //brk(free_manager);
            }
        }
    }
}


