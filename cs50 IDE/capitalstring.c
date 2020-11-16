/*
        //ASCII 코드에 부여된 글자의 고유번호를 이용, 소문자를 대문자로 전부 변환해주는 코드
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
*/


        //1st Substitution - ctype.h라는 헤더파일을 불러와 같은 기능을 수행
        //ASCII 코드에 부여된 글자의 고유번호를 이용, 소문자를 대문자로 전부 변환해주는 코드
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
