#include <stdio.h>


int main(void)
{
    int i, j;
    int gugudan[10][10]; // 왜 9 by 9의 array로 설정해놓고 실행을 하면 'Segment fault'가 뜨는가?
    for(i = 1; i <=9 ; i++)
    {
        printf("\n[%d단]\n", i);
        for (j = 1; j <= 9 ; j++)
        {
            gugudan[i][j] = i*j;
            printf("%d X %d = %d\n", i, j, gugudan[i][j]);
        }
    }
    return 0;
}

/*
7번째 줄에서 gugudan[10][10]을 설정했을 때 원소로서는 0~9의 index가 붙는다.
하지만, i와 j의 카운트로는 각각 1~9까지 카운트가 되기때문에 이를 맞춰주기 위해서는 각 줄마다 10개의 원소를 설정하는 것이다.
*/