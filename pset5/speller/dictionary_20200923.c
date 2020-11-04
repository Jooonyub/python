// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

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

int tableindex(const char *word)
{
    return tolower(word[0]-97)%N;
}

/*➜Next, notice that we’ve implemented load, hash, check, size, and unload, but only barely, just enough for the code to compile. Your job, ultimately, is to re-implement those functions as cleverly as possible so that this spell checker works as advertised. And fast!*/

// Returns true if word is in dictionary else false
bool check(const char *word) // index와 LENGTH는 동급으로 서로의 숫자 비교를 통해 알고리즘 전개
{
    //char c = word[0];
    //int firstletter = (tolower(c)-97)%N;
    //tmp = table[(tolower(word[0])-97)%N];
    //tmp = table[(atoi(word))];
    //tmp = table[(tolower(word[0])-97)%N];
    tmp = table[tableindex(word)];
    while(tmp != NULL)
    {
        if (strcasecmp(tmp->word,word) == 0)
        {
            return true;
            break;
        }
        tmp = tmp->next;

    }

    printf("%s\n",word);
    return false;
    /*
    char c = word[0];

    char smallword[strlen(word)+1];
    for (int j = 0; j < strlen(word)+1; j++)
    {
        smallword[j] = tolower(word[j]);
    }

    int firstletter = (tolower(c)-97)%N;
    tmp = table[firstletter];
    while(tmp != NULL)
    {
        if (strcmp(tmp->word,smallword) == 0)
        {
            return true;
            break;
        }
        tmp = tmp->next;

    }

    printf("%s\n",word);
    return false;
    */
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

    strcpy(n->word, word);
    n->next = NULL;

    tmp = table[firstletter];
    table[firstletter] = n;
    n->next = tmp;

    int loopcount = 0;

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

        fclose(inptr);
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



