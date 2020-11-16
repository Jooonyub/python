//week5 _ Data Structure
//practice3 _ Singly Linked List

#include <stdio.h>
#include <stdlib.h> //malloc 함수를 쓰기 위함

typedef struct node
{
    int number;
    struct node* next;
}
node;

int main(void)
{
    //head 선언 (이 때, NULL로 선언하기때문에 별도의 메모리할당 여부는 체크안해도 된다.)
    node *list = NULL;

    //node 선언
    node *n = malloc(sizeof(node));
    if (n != NULL) //n이 메모리할당이 되었다는 가정 하에 if문으로 들어간다.
    {
        n->number = 2; //포인터가 아니기 때문에 (*n).number=2로 쓰는게 정석이지만, 이 표현도 가능
        n->next = NULL; //초기에는 pointer가 아무것도 가리키지 않고 pointer의 자리만 차지하게끔 선언해주기
    }
    list = n; // 이 선언을 해줌으로써 n이라는 포인터가 가리키는 값 2를 list도 가리키게 된다.


    node *tmp = list; // list가 가리키는 값을 가리키는 임시 포인터 생성
    while (tmp->next != NULL) //tmp->next라는 포인터가 NULL포인터일때까지 진행
    {
        tmp = tmp->next; //tmp포인터를 temp->next포인터로 일치
    }
    tmp->next = n;
}