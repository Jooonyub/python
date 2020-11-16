//week5 _ Data Structure
//practice2-1 _ resizing arrays with only using malloc

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

    int *tmp = malloc(4*sizeof(int)); //값이 4개 들어가는 리스트 생성
    if (tmp == NULL)
    {
        return 1;
    }
/*
    //방법 ➀ _ for 루프를 통해 값들을 하나 하나 매칭시키기
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;
*/
    //방법 ➁ _ pointee를 일치시키기(서로 다른 origin에서 같은 target로 수렴한다고 생각하기)
    tmp = list;
    tmp[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n",tmp[i]);
    }
}

/*
해당 코드에서 list는 더이상 아무런 기능을 하지 않기 떄문에 free(list);를 해준걸로 보인다.
본 코드의 목적이 크기가 다른 새로운 array(list)를 할당해서 추가적인 값을 받는것이었음
*/