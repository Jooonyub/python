//포인터예제2

#include <stdio.h>

int main(void)
{
    int i = 10;
    int *p;
    p = &i;
    printf("i = %d // p = %p // &i = %p // *p = %d \n", i , p , &i , *p);
    *p = 20;
    printf("i = %d // p = %p // &i = %p // *p = %d \n", i , p , &i , *p);
    return 0;
}