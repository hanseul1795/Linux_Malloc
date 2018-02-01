#include <stdio.h>
#include "../include/Malloc.h"

int main()
{
    int* test = (int*)allocate_memory(sizeof(int) * 100);
    test[29] = 30;
    char* test2 = (char*)allocate_memory(sizeof(char) * 50);
    test2[0] = 'h';
    test2[1] = 'f';

    printf("%p\n", test);
    printf("%p\n", test2);

    //free_memory(test2);
    free_memory(test);
	float* test3 = (float*)allocate_memory(sizeof(float) * 10);
    test3[0] = 34234.f;
    printf("%p\n", test3);
    printf("%d\n", test[29]);
    free_memory(test2);
    free_memory(test3);
    return 0;
}
