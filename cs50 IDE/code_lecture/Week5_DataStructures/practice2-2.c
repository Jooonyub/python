//week5 _ Data Structure
//practice2-2 _ resizing arrays with only using malloc

#include <stdio.h>
#include <stdlib.h> //malloc 함수를 쓰기 위함

int main(void)
{
    int *list = malloc(3*sizeof(int));
    if (list == NULL) //혹여나 컴퓨터 메모리가 가득 차서 list에 대한 메모리할당이 제대로 이루어지지 않은 경우를 대비
    {
        return 1;
    }

    //pointer arithmetic을 통해 값 할당
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = realloc(list, 4*sizeof(int)); //realloc을 하면 list와 tmp 사이에는 어떤 연관성이 있는거지? 단순히 old data가 복사되었다는 부분?
    if (tmp == NULL)
    {
        return 1;
    }

    //tmp = list;  //--> 이 부분이 갖는 의미(Now, all we need to do is remember the location of the new array:) 생각해보기
    tmp[3] = 4;

    for (int i = 0; i<4; i++)
    {
        printf("%d\n",tmp[i]);
    }

    free(list);

}