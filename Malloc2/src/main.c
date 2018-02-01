#include <stdio.h>
#include "../include/Malloc.h"

int main()
{
    int* test = (int*)allocate_memory(sizeof(int) * 30);
    test[0] = 30;
    char* test2 = (char*)allocate_memory(sizeof(char) * 50);
    test2[0] = 'h';
    test2[1] = 'f';
    float* test3 = (float*)allocate_memory(sizeof(float) * 20);
    test3[0] = 4324.33f;		
    
    printf("%c\n", test2[0]);
    printf("%f\n", test3[0]);

    free_memory(test);
    free_memory(test2);
    free_memory(test3);	
    printf("%c\n", test2[1]);
    printf("%f\n", test3[0]);
    return 0;
}
