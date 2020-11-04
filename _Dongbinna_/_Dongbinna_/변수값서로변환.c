// 두 변수의 값을 서로 변환하는 포인터 함수

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int x = 1;
    int y = 2;
    printf("x = %d / y = %d\n", x, y);
    printf("&x = %p / &y = %p\n", &x, &y);
    swap(&x, &y);
    printf("x = %d / y = %d\n", x, y);
    printf("&x = %p / &y = %p\n", &x, &y);
    return 0;
}