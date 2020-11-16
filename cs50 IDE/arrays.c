#include <stdio.h>

void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = {0, 1, 2, 3};
    printf("%d %d %d\n", a, set_int(a), b[0]);
    set_int(a);
    printf("%d %d %d\n", a, set_int(a), b[0]);
    set_array(b);
    printf("%d %d %d\n", a, set_int(a), b[0]);
}

void set_array(int array[4])
{
    array[0] = 22;
}

void set_int(int x)
{
    x = 22;
}