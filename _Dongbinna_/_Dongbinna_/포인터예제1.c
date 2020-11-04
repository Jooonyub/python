// 포인터 예제

#include <stdio.h>

int main(void)
{
    int x = 70;
    int *y = &x;
    printf("x = %d // y = %p // *y = %d // &x = %p\n", x, y, *y, &x);
    return 0;
}