//2차원배열을 활용하여 학생들 점수의 합 구하기

#include <stdio.h>

int main(void)
{
    int score[5][2];// 학생 5명의 2과목 점수를 받아낸다.
    int total[2] = {0, }; //1차원 배열을 할당할때 모든 데이터의 값에 0을 넣어주겠다는 의미. 두개의 공간을 할당했기 때문에 index 0과 1이 있을 것.
    //int total[2]; 로 코드실행을 했을 경우 '5명의 수학 점수 합계'에 엉뚱한 값이 출력되는걸 봄
    int i;

    for (i=0; i<5; i++)
    {
        printf("%d번째 학생의 수학, 영어 점수 : ", i+1);
        scanf("%d %d", &score[i][0], &score[i][1]);
    }

    for (i=0; i<5; i++)
    {
        total[0] += score[i][0];
        total[1] += score[i][1];
    }
    printf("\n\n 5명의 수학 점수 합계 : %d\n", total[0]);
    printf("5명의 영어 점수 합계 : %d\n", total[1]);
    return 0;
}