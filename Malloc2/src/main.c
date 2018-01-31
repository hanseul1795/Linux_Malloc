#include <stdio.h>
#include "../include/Malloc.h"

int main()
{
    int* test = (int*)allocate_memory(sizeof(int) * 30);
    test[0] = 30;
    printf("%d\n", test[0]);

    free_memory(test);

    printf("%d\n", test[0]);

    char* test2 = (char*)allocate_memory(sizeof(char) * 50);
    test2[0] = 'h';
    test2[1] = 'f';

    printf("%c\n", test2[0]);
    printf("%c\n", test2[1]);

    free_memory(test2);

    printf("%c\n", test2[0]);
    printf("%c\n", test2[1]);
    return 0;
}
