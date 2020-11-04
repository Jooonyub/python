//Pset1 - Credit
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

//int get_correct_long (string prompt);

int main(void)
{
    long credit = get_long("Number: ");

    long testcredit = credit;
    int i;
    int sum = 0;                    // sum이 루프 안으로 들어가면 계속 초기화되는 문제

    for (i = 1; i <= 16; i++)       // 가능한 자리수의 최대치
    {

        int num = testcredit % 10;               //각 자리의 숫자를 추출하기
        if (i % 2 == 0)                     //끝부터짝수의 자리의 수는 2배
        {
            num = num*2;
            if (num >= 10)                  //민액 2배를 한 수가 10을 넘어간다면 각각의 수를 더한다.
            {
                //for (int j = 1; j < 3; j++)
                //{
                num = (num / 10) + (num % 10);       //10을 넘어가는 수들을 먼저 더하고
                //}
            }
            sum = sum + num;                //끝부터짝수의 2배수중 10을 넘어가지 않는 수들 덧셈
        }
        else
        {
            sum = sum + num;
        }
        testcredit = testcredit/10;
        if (testcredit == 0)
        {
            break;
        }
    }

    if (sum % 10 == 0)
    {
        //유효할 수 있는 조건(Luhn's Algorithm)에는 일단 해당!
        if(i == 15)
        {
            if ((credit / 10000000000000) == 34 || (credit / 10000000000000) == 37)
            {
                printf("AMEX\n");
                return 0;
            }
            else
            {
                printf("invalid\n");
                return 1;
            }
        }
        else if (i == 16)
        {
            if ((credit / 100000000000000) == 51 || (credit / 100000000000000) == 52 || (credit / 100000000000000) == 53 || (credit / 100000000000000) == 54 || (credit / 100000000000000) == 55 )
            {
                printf("MASTER CARD\n");
                return 0;
            }
            else if ((credit / 1000000000000000) == 4)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("invalid\n");
                return 1;
            }
        }
        else if (i == 13)
        {
            if ((credit / 10000000000000) == 4)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("invalid\n");
                return 1;
            }
        }

        else
        {
            printf("invalid\n");
            return 1;
        }

    }
    else
    {
        printf("invalid\n");
        return 1;
    }
}

/*
int get_correct_long (string prompt)
{
    long credit;
    while(true)
    {
        credit = get_long("%s", prompt);
        if (isdigit(credit) != 0)
        {
            break;
        }
    }
    return credit;


    long credit;
    do
    {
        credit = get_long("%s", prompt);
    }
    while (isdigit(credit) != true);
    return credit;

}
*/
