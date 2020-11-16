/*
        //이름을 한 글자 한 글자 출력해서 나타내기
        //Original code in PDF
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("What is Your name?\n");
    printf("Output : ");
    for (int i=0; i < strlen(s); i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}
*/
/*
        //이름을 한 글자 한 글자 출력해서 나타내기
        //1st Substitution code - strlen이라는 내장함수 사용
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("What is Your name?\n");
    printf("Output : ");
    int n = strlen(s);
    for (int i=0; i < n; i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}
*/
        //이름을 한 글자 한 글자 출력해서 나타내기
        //2nd Substitution code - string의 마지막 바이트에 \0이 쓰인다는 것을 활용한 code
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("What is Your name?\n");
    printf("Output : ");
    for (int i=0; s[i] != '\0'; i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}


