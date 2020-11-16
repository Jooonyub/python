// Implements a list of numbers with an array of dynamic size
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // List of size 3
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    // Initialize list of size 3 with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // List of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    // Copy list of size 3 into list of size 4
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // Add number to list of size 4
    tmp[3] = 4;

    // Free list of size 3
    free(list);

    // Remember list of size 4
    list = tmp;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);
}


/*
[코드 해석] 2020.08.29

9       동적메모리 할당을 통해 크기 3*sizeof(int)의 list라는 int pointer를 만들어준다.
10~13   할당할 수 있는 메모리가 있는지 여부를 체크하는 코드. list==NULL이면 할당할 메모리가 남아있지 않다는 뜻이고, 따라서 전체 코드는 return값 1을 출력하며 종료
16~18   각 요소별로 값을 넣어 초기화해준다.
21      동적메모리 할당을 통해 크기 4*sizeof(int)의 tmp라는 int pointer를 만들어준다.
22~25   할당할 수 있는 메모리가 있는지 여부를 체크하는 코드. tmp==NULL이면 할당할 메모리가 남아있지 않다는 뜻이고, 따라서 전체 코드는 return값 1을 출력하며 종료
28~31   for문을 통해 list의 요소 값들을 tmp의 요소 값으로 써줌
34      tmp의 4번째 값은 직접 입력(list는 크기가 3이고, tmp는 크기가 4이기 때문에 따로 입력해주는 수밖에 없다.)
37      동적메모리 할당을 통해 선언해준 list의 메모리할당을 해제해줌
40      list와 tmp 두 int pointer의 pointee를 일치시켜줌(list의 pointee를 tmp의 pointee로 변경)
43~46   for문을 통해 각 4개 요소의 list값들을 printf해줌
37      list의 메모리할당을 해제해줌 (pointer 기능을 해제시켜주는 듯..?)

*/