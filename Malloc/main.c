#include <stdio.h>
#include "include/Malloc.h"

int main()
{

    int* test = (int*)allocate_memory(20);
    test[0] = 30;
    free_memory(test);

    printf("%d\n", test[0]);
  /*  int* test2 = (int*)allocate_memory(20);
    test2[0] = 30;
    free_memory(test2);

    printf("%p\n", test2);*/
    return 0;
}