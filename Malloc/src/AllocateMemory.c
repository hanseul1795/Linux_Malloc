//
// Created by h.shin on 1/29/18.
//

#include "../include/AllocateMemory.h"

void* first_block_address = NULL;

void initlialize_block(t_block* p_b)
{
    if(!p_b)
        return;

    p_b->next_block = NULL;
    p_b->prev_block = NULL;
    p_b->size = 0;
    p_b->free = false;
    p_b->data = NULL;
}

t_block* extend_heap(size_t p_size)
{
    if(p_size == 0)
        return NULL;

    t_block* temp = NULL;
    temp = sbrk(sizeof(t_block) + p_size);
    if(temp == (void*) -1)
        return NULL;

    initlialize_block(temp);
    temp->size = p_size;
    return temp;
}

void* my_malloc(size_t p_size)
{
    if(p_size == 0)
        return NULL;

    t_block* prev = NULL;
    t_block* temp;
    temp = extend_heap(p_size);
    if(temp == NULL)
        return NULL;

    if(first_block_address == NULL)
        first_block_address = temp;

    else
    {
        t_block* last = first_block_address;
        while(last != NULL)
        {
            last = last->next_block;
        }
        last->prev_block->next_block = temp;
        temp->prev_block = last->prev_block;
        last = temp;

    }
    return temp->data;
}

void my_free(void *p_ptr)
{

}

t_block* find_block(size_t p_size)
{
    t_block* temp = first_block_address;
    while(temp && !temp->free && temp->size < p_size)
    {
        temp = temp->next_block;
    }
    return temp;
}

void split_block(t_block* p_b, size_t p_size)
{
    if(p_b == NULL || p_size == 0)
        return ;

    t_block* split;
    split = p_b->data + p_size;
    split->size = p_b->size - p_size - sizeof(t_block);
    split->next_block = p_b->next_block;
    split->free = true;
    p_b->size = p_size;
    p_b->next_block = split;
}

t_block* try_to_fuse(t_block* p_b)
{
    if(p_b == NULL)
        return NULL;

    if(p_b->next_block && p_b->next_block->free)
    {
        p_b->size += sizeof(t_block) + p_b->next_block->size;
        p_b->next_block = p_b->next_block->next_block;
        if(p_b->next_block != NULL)
        {
            p_b->next_block->prev_block = p_b;
        }
    }
    return p_b;
}
