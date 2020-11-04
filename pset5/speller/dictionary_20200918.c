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
        printf("In the function of check, 'tmp->word' is : %s\t'smallword' is :%s\n", tmp->word, smallword);
        if (strcmp(tmp->word,smallword) == 0)
        {
            printf("words in dictionary : %s\n", word);
            return true;
            break;
        }
        //tmp = tmp->next;
        //printf("%s\n", tmp->next->word);
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

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //node *head = NULL;

    char c = word[0]; //단어의 마지막이 아니라 파일의 맨 끝부분이 나오면 EOF 출력
    int firstletter = (tolower(c)-97)%N;
    //tmp = table[firstletter];

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return false;
    }

    //printf("In the function hash, 'n->word' is : %s\t 'word' is : %s\n",n->word, word); // 여기서는 아직 n->word에 담기기 전이니까 아무것도 출력이 안됨
    strcpy(n->word, word);
    n->next = NULL;

    if (table[firstletter] == NULL)
    {
        table[firstletter] = n;
        tmp = table[firstletter];
    }

    while(tmp != NULL)
    {
        tmp = tmp->next;
    }
    tmp = n;

    for (node *pt = table[firstletter]; pt != NULL; pt = pt->next)
    {
        printf("%s\n",pt->word);
    }

    //printf("In the function hash, 'n->word': %s\t 'word': %s\t'tmp->word':%s\t'table[firstletter]->word:%s\n'\n",n->word, word, tmp->word, table[firstletter]->word);

///////////////////////////////이상 2020.09.16 수
/*수요일에 관한 출력화면*/
/*
.
.
.
OUT
THE
END

WORDS MISSPELLED:     17314
WORDS IN DICTIONARY:  0
WORDS IN TEXT:        17756
TIME IN load:         0.02
TIME IN check:        0.01
TIME IN size:         0.00
TIME IN unload:       0.00
TIME IN TOTAL:        0.03
*/

    //table[firstletter] = n;


    //for (int j = 0; j < N; j++)
    /*
    node *tmp = NULL;
    if (table[firstletter] == NULL)
    {
        table[firstletter] =
    }

    strcpy(table[firstletter]->word,word);
    table[firstletter]->next = NULL;

    table[firstletter] = table[firstletter]->next;
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

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    if ((strcmp(dictionary,"dictionaries/large")) == 0 || (strcmp(dictionary,"dictionaries/small") == 0))

    {
        /*
        FILE *inptr = malloc(sizeof(FILE));
        inptr = fopen(dictionary,"r"); // 언제 닫아야하지..?
        */

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

        /*2020.09.16 기존의 for문 구성에서 hash함수를 넣은 while문으로 바꿔보고자 주석처리함!!!!
        for (node *n = malloc(sizeof(node)); fscanf(inptr, "%s", dicword) != EOF; n = malloc(sizeof(node)))
        {

            //node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                printf("memory allocation failure");
                return false;
            }

            strcpy(n->word,dicword);
            n->next = NULL;

            if (dichead == NULL)
            {
                dichead = n;
            }
            hash(dicword);
            //printf("%s\n",n->word);
        }
        */

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

/*
    if (dichead != NULL)
    {
        tmp = NULL;
        char dicword[LENGTH+1];
        int wordcount = 0;
        tmp = dichead;
        //while(fscanf(inptr, "%s", dicword) != EOF)
        while (tmp != NULL)
        {
            //printf("%s\n", dicword);
            tmp = tmp->next;
            wordcount++;
        }
        //printf("\ntotal words : %d",count);
        return wordcount;
    }
    return 0;
*/
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



