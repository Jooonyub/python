//float형 데이터로 산술연산을 할 때 주의해야 할 점을 알아보기 위해 작성한 코드

#include <stdio.h>

int main(void)
{
    /*
    printf("Mathematical operations - Only Integers\n");
    int a = 13;
    int b = 3;
    int addition = a+b;
    int subtraction = a-b;
    int multiple = a*b;
    int division = a/b;
    int remnant = a%b;

    printf("int형으로 선언한 두 변수 a와 b?\t a : %i & b : %i\n", a, b);
    printf("two numbers : %i & %i\n + : %i\n - : %i\n * : %i\n /  : %i\n %%  : %i\n\n", a, b, addition, subtraction, multiple, division, remnant);
    printf("만약 int형으로 선언한 두 변수 a와 b을 float형으로 나타내어본다면?\t a : %f & b : %f\n", (float)a, (float)b);
    //printf("만약 int형으로 선언한 두 변수 a와 b을 float형으로 나타내어본다면?\t a : %d & b : %d\n", (double)a, (double)b);
    */

    /*
    printf("Mathematical operations - Only Floats\n");
    float a = 13.6;
    float b = 3.25;
    float addition = a+b;
    float subtraction = a-b;
    float multiple = a*b;
    float division = a/b;
    float remnant = (int)a % (int)b;

    //printf("Guess What? (int)a is %i, and (int)b is %i\n", (int)a, (int)b);
    printf("two numbers : %f & %f\n + : %f\n - : %f\n * : %f\n / : %f\n %%는 정수형끼리의 연산에서만 진행이 된다.\n\n", a, b, addition, subtraction, multiple, division);
    printf("float형으로 선언한 두 변수 a와 b?\t a : %f & b : %f\n", a, b);
    printf("만약 float형으로 선언한 두 변수 a와 b을 int형으로 나타내어본다면?\t a : %i & b : %i\n", (int)a, (int)b);
    //printf("만약 float형으로 선언한 두 변수 a와 b을 double형으로 나타내어본다면?\t a : %d & b : %d\n", (double)a, (double)b);
    */


    printf("Mathematical operations - Only Doubles\n");
    double a = 13.6;
    double b = 3.24;
    double addition = a+b;
    double subtraction = a-b;
    double multiple = a*b;
    double division = a/b;
    double remnant = (int)a % (int)b;


    //printf("Guess What? (int)a is %i, and (int)b is %i\n", (int)a, (int)b);
    //printf("two numbers : %d & %d\n + : %d\n - : %d\n * : %d\n / : %d\n %%는 정수형끼리의 연산에서만 진행이 된다.\n\n", a, b, addition, subtraction, multiple, division);
    //printf("double형으로 선언한 두 변수 a와 b?\t a : %d & b : %d\n", a, b);
    printf("만약 double형으로 선언한 두 변수 a와 b을 int형으로 나타내어본다면?\t a : %i & b : %i\n", (int)a, (int)b);
    printf("만약 double형으로 선언한 두 변수 a와 b을 float형으로 나타내어본다면?\t a : %f & b : %f\n", (float)a, (float)b);

    /*
    float a = 0.04;
    float b = 0.01;
    float c = a / 0.01;
    int d = a / 0.01;
    printf("a is %f\tb is %f\tc is : %f\t and d is %i\n", a, b, c, d);
    return 1;
    */
}