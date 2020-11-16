//week5 _ Data Structure
//practice1 _ pointers and malloc(memory allocation)

#include <stdio.h>
#include <stdlib.h>

//linked list라는 data structure을 선언
typedef struct node
{
    int number;
    struct node* next;
}
node;

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    *y = 13;
}