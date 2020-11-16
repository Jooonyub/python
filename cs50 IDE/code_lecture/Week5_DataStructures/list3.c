// Implements a list of numbers with linked list

#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // List of size 0
    node *list = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}


/*
7~12    node라는 data structure을 정의(하나의 nonpointer와 하나의 pointer를 가지는 structure을 node라 명명하기

14      main 함수 시작

17      list라는 이름의 node pointer를 선언(NULL로 초기화)

20      n이라는 이름의 node pointer를 선언(동적 메모리할당 malloc으로 메모리 지정)
21~24   메모리가 제대로 할당되었는지 체크

25      n이라는 node pointer의 number라는 int에 1로 초기화
26      n이라는 node pointer의 next라는 node pointer에 NULL로 초기화
27      list의 pointee를 n의 pointee로 일치시키기(이때 n의 pointee가 가리키는 것 = n->next가 가리키는 것 = NULL?)

30      n이라는 이름의 node pointer를 선언(동적 메모리할당 malloc으로 메모리 지정)  = line20
31~34   메모리가 제대로 할당되었는지 체크

35      n이라는 node pointer의 number라는 int에 2로 초기화
36      n이라는 node pointer의 next라는 node pointer에 NULL로 초기화
37      list->next의 pointee를 n의 pointee로 일치시키키

40      n이라는 이름의 node pointer를 선언(동적 메모리할당 malloc으로 메모리 지정)  = line20
41~44   메모리가 제대로 할당되었는지 체크

45      n이라는 node pointer의 number라는 int에 3으로 초기화
46      n이라는 node pointer의 next라는 node pointer에 NULL로 초기화
47      list->next->next의 pointee를 n의 pointee로 일치시키기(이때 n의 pointee가 가리키는 것 = n->next가 가리키는 것 = NULL?)

50~53   for문을 이용하여서 초기조건, 조건문, 반복실행문을 설정하고 매회 tmp->number을 출력

56~61   while문을 이용, 조건은 list가 NULL이 아닌 경우에는 항상 돌아갈 수 있도록 함
        tmp라는 node pointer의 pointee는 list->next의 pointee와 일치시켜주기
        그 후에 list의 동적 메모리 할당 해제(pointer 기능 해제)
        그 후 list의 pointee를 tmp의 pointee로 일치시켜주기
*/
