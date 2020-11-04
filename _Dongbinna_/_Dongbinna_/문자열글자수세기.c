// 하나의 문자열 안에 있는 글자의 수 세기

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[1001];
    getc(input);
    int count = 0;
    while (input[count] != '\0')
    {
        count++;
    }
    printf("입력한 문자열의 길이는 %d입니다.", count);
    return 0;
}