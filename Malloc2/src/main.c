#include <stdio.h>
#include <bits/time.h>
#include <time.h>
#include <string.h>
#include "../include/MemoryManagement.h"

int main()
{

    int* test = (int*)allocate_memory(sizeof(int) *50);
    test[0] = 1;
    test[2] = 2;
    test[3] = 3;
    test[4] = 4;
    test[5] = 5;
    printf("%d\n", test[4]);
    test = (int*)reallocate_memory(test, sizeof(int) *3);

    printf("%d\n", test[0]);
    printf("%d\n", test[4]);
    return 0;
}