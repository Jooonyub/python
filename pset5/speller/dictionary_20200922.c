// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

/*	➜Now open up dictionary.c. Notice how, atop the file, we’ve defined a struct called node that represents a node in a hash table. */

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

/*➜And we’ve declared a global pointer array, table, which will (soon) represent the hash table you will use to keep track of words in the dictionary. The array contains N node pointers, and we’ve set N equal to 1 for now, meaning this hash table has just 1 bucket right now. You’ll likely want to increase the number of buckets, as by changing N, to something larger!*/

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N]; //이 자체가 head처럼 역할하지 않을까..?


int dicnum = 0;
node *tmp = NULL;

/*➜Next, notice that we’ve implemented load, hash, check, size, and unload, but only barely, just enough for the code to compile. Your job, ultimately, is to re-implement those functions as cleverly as possible so that this spell checker works as advertised. And fast!*/

// Returns true if word is in dictionary else false
bool check(const char *word) // index와 LENGTH는 동급으로 서로의 숫자 비교를 통해 알고리즘 전개
{
    // TODO
    /*
    1. word의 첫 글자를 파악하여 table의 몇번째 index에 속하는지 먼저 파악
    2. indexing된 hashtable의 linked list를 따라 처음부터 시작, 쭉 가면서 겹치는 단어가 있는지 확인
    */
    char c = word[0];

    char smallword[strlen(word)+1];
    for (int j = 0; j < strlen(word)+1; j++)
    {
        smallword[j] = tolower(word[j]);
    }
    //printf("%s\n", smallword);

/*
    int firstletter = (tolower(c)-97)%N;
    //node *head = NULL; // 이걸 먼저 선언하지 않으면 for루프에서 head를 사용할 수 없을것같지않나..?
    int cmpnum = 0;
    for (tmp = table[firstletter]; tmp != NULL; tmp = tmp->next)
    {
        char *charofword;
        charofword = tmp->word;
        char smallword[strlen(word)+1];
        for (int j = 0; j < strlen(word)+1; j++)
        {
            smallword[j] = tolower(word[j]);
            cmpnum += strcmp(&charofword[j],&smallword[j]);
        }
        if (cmpnum == 0)
        {
            printf("words in dictionary : %s\n", word);
            return true;
            //break;
        }
    }
*/
    int firstletter = (tolower(c)-97)%N;
    tmp = table[firstletter];
    while(tmp != NULL)
    {
        //printf("In the function of check, 'tmp->word' is : %s\t'smallword' is :%s\n", tmp->word, smallword);
        if (strcmp(tmp->word,smallword) == 0)
        {
            //printf("words in dictionary : %s\n", word); //사전에서 검색되는 단어는 그대로 출력
            return true;
            break;
        }
        tmp = tmp->next;
        //printf("%s\n", tmp->word);
    }
    /*
    for (tmp = table[firstletter]; tmp != NULL; tmp = tmp->next)
    {
        printf("In the function of check, 'tmp->word' is : %s\t'smallword' is :%s\n", tmp->word, smallword);
        if (strcmp(tmp->word,smallword) == 0)
        {
            printf("words in dictionary : %s\n", word);
            return true;
            break;
        }
    }
    */
    printf("%s\n",word);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO

    char c = word[0]; //단어의 마지막이 아니라 파일의 맨 끝부분이 나오면 EOF 출력
    int firstletter = (tolower(c)-97)%N;
    //tmp = table[firstletter];

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return false;
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
/*
    if (table[firstletter] == NULL)
    {
        table[firstletter] = n;
        tmp = table[firstletter];
    }
*/
    //printf("➀%s\n",tmp->word); //➀ 여기서는 tmp와 table[firstletter]가 일치해야 하는게 맞음
/*
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp = n;
*/
    //printf("➁tmp->word: %s\tn->word:%s\n", tmp->word, n->word); // ➁ 여기서는 tmp가 가장 최근에 입력된 단어여야하는데, 처음값이 계속 찍혀나옴

    int loopcount = 0;
    //해당 firstletter에 대해 저장된 linked lists의 word을 차례대로 나열함이 원래 목적인 반복문
    /*
    for (node *pt = table[firstletter]; pt != NULL; pt = pt->next) //해당 hash table에 있는 것들은 다 출력이 되어야하는데, 왜 첫번째것밖에 출력이 안되는걸까? 바로 NULL이 나온다는 얘긴데..
    {
        loopcount++;
        printf("➂ %s\tloopcount: %d\n",pt->word, loopcount);

    }
    */

    //printf("In the function hash, 'n->word': %s\t 'word': %s\t'tmp->word':%s\t'table[firstletter]->word:%s\n'\n",n->word, word, tmp->word, table[firstletter]->word);

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

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    if ((strcmp(dictionary,"dictionaries/large")) == 0 || (strcmp(dictionary,"dictionaries/small") == 0))

    {

        FILE *inptr = fopen(dictionary,"r"); // 언제 닫아야하지..?
        //dict = (FILE *)malloc(sizeof(FILE));
        if (inptr == NULL)
        {
            printf("dictionary file open failure");
            return false;
        }

        char dicword[LENGTH+1];
        while (fscanf(inptr, "%s", dicword) != EOF)
        {
            hash(dicword);
            dicnum++;
        }

//하나의 table index에 속한 linked list들의 연결을 여기서 해줘야할것같은데.....//

        //printf("%s\n",dichead->word);
        fclose(inptr);
        //table[0] = inptr; //dictionary랑 table을 연결해야하는건가..? node *와 FILE *가 다르기떄문에 이 줄은 에러가 나는 상태(2020.09.10)????????????
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int sum = 0;
    int k = 0;
    for (int j =0; j < N; j++)
    {
        if(table[j] == NULL)
        {
            k = 0;
        }
        else
        {
            k = 1;
        }
        sum = sum + k;
    }

    if (sum != 0)
    {
        return dicnum;
    }
    return 0;

}


// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    //node *head = NULL;
    for (int j = 0; j < N; j++)
    {
        node *curr = NULL;
        tmp = table[j];

        while (tmp != NULL)
        {
            curr = tmp->next;
            free(tmp);
            tmp = curr;
        }
        if (tmp == NULL)
        {
            return true;
        }
    }

    return false;
    //2020.09.10 dict는 어디서 왔고, file은 어디서 왔지???

}



