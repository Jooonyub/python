#include <stdio.h>
#include <cs50.h>

// Each pair has a winner, loser
typedef struct
{
    string winner;
    string loser;
}
pair;

//int pair_count = 4;

pair pairs[4];

//char alice, bob, charlie, david;

void add_pairs(void);
void sort_pairs(void);

int main(void)
{

    add_pairs();

    pair pairs_copy[4];

    for (int i = 0; i < 4; i++)
    {
        pairs_copy[i] = pairs[i];
        printf("before _ pairs[%i].winner & pairs[%i].loser\t %s & %s\n", i,i, pairs[i].winner, pairs[i].loser);
        //printf("pairs[%i].winner : %c \npairs[%i].loser : %c", i,i, pairs[i].winner, pairs[i].loser);
        printf("\n");
    }

    pairs[0] = pairs_copy[3];
    for (int i = 0; i < 4; i++)
    {
        //printf("before _ pairs[%i].winner & pairs[%i].loser\n", i,i);
        printf("pairs[%i].winner : %s \npairs[%i].loser : %s", i, pairs[i].winner, i, pairs[i].loser);
        printf("\n");
    }
    /*
    sort_pairs();
    for (int i = 0; i < 4; i++)
    {
        printf("before _ pairs[%i].winner & pairs[%i].loser\n", i,i);
        printf("pairs[%i].winner : %c \npairs[%i].loser : %c", i,i, pairs[i].winner, pairs[i].loser);
        printf("\n");
    }
    */
    return 0;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pairs[0].winner = "charlie";
    pairs[0].loser = "bob";

    pairs[1].winner = "bob";
    pairs[1].loser = "charlie";

    pairs[2].winner = "charlie";
    pairs[2].loser = "david";

    pairs[3].winner = "david";
    pairs[3].loser = "alice";
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pairs[0] = pairs[1];
    pairs[1] = pairs[2];
    pairs[2] = pairs[3];
    pairs[3] = pairs[0];
    return;
}




/*
핵심은!!!!
모든 array에 대해서는 string이 아니라 int가 들어가는 것같다.
*/