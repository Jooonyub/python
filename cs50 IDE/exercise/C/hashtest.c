#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 45

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

node *tmp = NULL;

// Hash table
node *table[N]; //이 자체가 head처럼 역할하지 않을까..?

unsigned int hash(const char *word);

int main(void)
{
    hash("a");
    hash("aaa");
    hash("aaas");
    hash("aachen");
    hash("aalborg");
    hash("aalesund");
    hash("aardvark");
    hash("aardvark's");

    tmp = table[0];
    int whilecount = 0;
    while(tmp->next != NULL)
    {
        whilecount++;
        tmp = tmp->next;
        printf("word(whilecount) : %s(%d)\t",tmp->word,whilecount);
    }
}


unsigned int hash(const char *word)
{
    // TODO

    char c = word[0]; //단어의 마지막이 아니라 파일의 맨 끝부분이 나오면 EOF 출력
    int firstletter = (tolower(c)-97)%N;
    //tmp = table[firstletter];

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 0;
    }
/*
    if (table[firstletter] == NULL)
    {
        table[firstletter] = n;
        tmp = table[firstletter];
    }
*/
    //printf("In the function hash, 'n->word' is : %s\t 'word' is : %s\n",n->word, word); // 여기서는 아직 n->word에 담기기 전이니까 아무것도 출력이 안됨
    strcpy(n->word, word);
    n->next = NULL;


    tmp = table[firstletter];
    table[firstletter] = n;
    n->next = tmp;

    printf("➀%s\n",tmp->word); //➀ 여기서는 tmp와 table[firstletter]가 일치해야 하는게 맞음
/*
    while(tmp->next != NULL) // 이게 아예 이 줄에서 false가 되어 link가 형성되지 않았다는 말밖에 안됨
    {
        tmp = tmp->next;
    }
*/
    tmp = n;
    printf("➁tmp->word: %s\tn->word:%s\n", tmp->word, n->word); // ➁ 여기서는 tmp가 가장 최근에 입력된 단어여야하는데, 처음값이 계속 찍혀나옴

    int loopcount = 0;
    //해당 firstletter에 대해 저장된 linked lists의 word을 차례대로 나열함이 원래 목적인 반복문
    for (node *pt = table[firstletter]; pt != NULL; pt = pt->next) //해당 hash table에 있는 것들은 다 출력이 되어야하는데, 왜 첫번째것밖에 출력이 안되는걸까? 바로 NULL이 나온다는 얘긴데..
    {
        loopcount++;
        printf("➂ %s\tloopcount: %d\n",pt->word, loopcount);

    }

    //printf("In the function hash, 'n->word': %s\t 'word': %s\t'tmp->word':%s\t'table[firstletter]->word:%s\n'\n",n->word, word, tmp->word, table[firstletter]->word);

    /// 2020.09.12 알파벳별로 table에 hasing하기!!!!!!!if c%

    return 0;
}