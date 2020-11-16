#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned int hash(const char *word);

int main(void)
{
    hash("abcd");
    hash("cdab");
}

unsigned int hash(const char *word)
{
    // TODO
    int N = 26;
    //for (int j = 0; j < N; j++)
    char c = word[0]; //단어의 마지막이 아니라 파일의 맨 끝부분이 나오면 EOF 출력
    int firstletter = (tolower(c)-97)%N;
    printf("since the first letter is : %c, the index would be %d\n",c,firstletter);
/*
    strcpy(table[firstletter].node->word,word);
    table[firstletter].node->next = NULL;
*/
    //이상 2020.09.14 작성
    /*
    while(1)
    {
        int c = fgetc(word)
        if (c == EOF)
        {
            break;
        }
        int firstletter = (tolower(c)-97)%N
        table[firstletter]->
    }
    */

    /// 2020.09.12 알파벳별로 table에 hasing하기!!!!!!!if c%

    return 0;
}