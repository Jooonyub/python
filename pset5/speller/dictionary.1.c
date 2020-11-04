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

node *dichead = NULL;

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
    int firstletter = (tolower(c)-97)%N;
    node *head = NULL; // 이걸 먼저 선언하지 않으면 for루프에서 head를 사용할 수 없을것같지않나..?

    for (node *tmp = table[firstletter]; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(tmp->word,word) == 0)
        {
            return true;
            break;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //N = 26;
    //node *head = NULL;

    /*
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return false;
    }
    */

    //for (int j = 0; j < N; j++)
    char c = word[0]; //단어의 마지막이 아니라 파일의 맨 끝부분이 나오면 EOF 출력
    int firstletter = (tolower(c)-97)%N;

    strcpy(table[firstletter]->word,word);
    table[firstletter]->next = NULL;

    table[firstletter] = table[firstletter]->next;
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
        //for (int j = 0; fscanf(inptr, "%s", dicword) != EOF; node *n = malloc(sizeof(node)))
        {

            //node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                printf("memory allocation failure");
                return false;
            }

            if (n->next == NULL)
            {
                dichead = n->next;
            }
            strcpy(n->word, dicword);
    		n->next = NULL;


//하나의 table index에 속한 linked list들의 연결을 여기서 해줘야할것같은데.....//
        }
        fclose(inptr);
        //table[0] = inptr; //dictionary랑 table을 연결해야하는건가..? node *와 FILE *가 다르기떄문에 이 줄은 에러가 나는 상태(2020.09.10)????????????
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    /*
    char *dictionary = (argc == 3) ? argv[1] : DICTIONARY; // argc가 3인 경우에는 dictionary에 argv[1](즉, 써놓은 값)을, 그렇지 않은 경우에는 DICTIONARY를 쓴다.
    FILE *inptr = fopen(dictionary,"r"); // 언제 닫아야하지..?
    if (inptr == NULL)
    {
        printf("memory allocation failure");
        return false;
    }
    */

    char *dictionary = (argc == 3) ? argv[1] : DICTIONARY;
    FILE *inptr = fopen(dictionary,"r");
    if (load(dictionary) == 1)
    {
        char dicword[LENGTH+1];
        int wordcount = 0;
        while(fscanf(inptr, "%s", dicword) != EOF)
        {
            printf("%s\n", dicword);
            wordcount++;
        }
        //printf("\ntotal words : %d",count);
        return wordcount;
    }
    else
    {
        return 0;
    }
    //char *dictionary = (argc == 3) ? argv[1] : DICTIONARY;
    /*
    char *checkline = NULL;
    int wordcount = 0;
    if (load(dictionary) == true) // if(true)? // 여기서 load(dictionary를 선언하게 되면 dictionary가 뭔지 이 자체 함수에서 모르는 에러가 발생)
    {
        while (fread(checkline,sizeof(char),1,dict)==1)
        {
            if (checkline == "\n")
            {
                wordcount++;
            }
        }
        return wordcount;
    }
    */
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
        node *tmp = table[j];

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

    /*
    fclose(FILE *dict);
    if (dict == NULL)
    {
        return true;
    }
    return false;


    // TODO
    fclose(dict);
    if (file == NULL)
    {
        return true;
    }
    */
    return false;
    //2020.09.10 dict는 어디서 왔고, file은 어디서 왔지???

}



