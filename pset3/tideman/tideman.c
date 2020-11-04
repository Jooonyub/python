#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int k = 0; k < candidate_count; k++)
    {
    	if (strcmp(candidates[k],name) == 0)		//입력한 이름이 후보자 명단에 있는 경우
    	{
    		ranks[rank] = k;
    		return true;
    	}
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{

    for (int j = 0; j < candidate_count; j++)		//main 비교 숫자 rank
    {
    	for (int k = 0; k < candidate_count; k++)	//비교를 위해 쓰이는 숫자
    	{
    		if (j == k)		//j = k인 경우(동일인물 -> 비교 불가)
    		{
    			preferences[ranks[j]][ranks[k]] = 0;
    		}
    		else if (j < k)					//j < k인 경우(해당하는 preference에 +1)
    		{
    			preferences[ranks[j]][ranks[k]]++;
    		}
    		// j > k인 경우는 성립하지 않으므로 패스
    	}
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{

    for (int i = 0; i < candidate_count; i++)
    {
    	for (int j = i+1; j < candidate_count; j++)
    	{
    	    int k = i * (candidate_count - 1) + j -1; //k는 0부터 candidate_count^2까지
    	    //이건 결국 candidate_count에 대한 전체 2차원 행렬만큼의 array를 만들어서 접근한다는 뜻..
    	    //count가 되지 않은 index에 대한 건너뛰기가 상당히 귀찮을걸로 예상된다..
    		if (preferences[i][j] > preferences[j][i])
    		{
    			pairs[pair_count].winner = i;
    			pairs[pair_count].loser = j;
    			pair_count++;
    		}
    		else if ((preferences[i][j] < preferences[j][i]))
    		{
    			pairs[pair_count].winner = j;
    			pairs[pair_count].loser = i;
    			pair_count++;
    		}
    		// k++; 이미 루프의 변화조건에 따라 초기에 k값을 지정해주고 있기때문에 이것까지 하면 이중으로 영향을 끼치는 셈
    	}
    }
    printf("pair_count is : %i\n", pair_count);
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair pairs_copy[pair_count];
	int strength[pair_count];
	int strength_order[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
    	strength[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    	pairs_copy[i] = pairs[i];
    	strength_order[i] = strength[i];
    	printf("pairs[%i] : (winner : %i (name : %s), loser: %i (name : %s)) is = %i\n", i, pairs[i].winner, candidates[pairs[i].winner], pairs[i].loser, candidates[pairs[i].loser], strength[i]);
    }

    //.여기가 문제였구나! 왜 문제지..? strength_order[pair_count] = strength[pair_count];
    printf("initial _ strength[0] : %i, strength[1] : %i, strength[2] : %i\n", strength[0], strength[1], strength[2]);
    printf("initial _ strength_order[0] : %i, strength[1] : %i, strength[2] : %i\n", strength_order[0], strength_order[1], strength_order[2]);
	for (int i = 0; i < pair_count; i++)
	{

        //pairs[i] = pairs_copy[i];
		for (int j = i+1 ; j < pair_count; j++)
		{
			if (strength_order[i] < strength[j])	// 배열순서상 뒤에 위치한 index의 strength가 더 큰 경우
			{
				//pairs[i] = pairs_copy[j];
				//pairs_copy[j] = pairs_copy[i];
				strength_order[i] = strength[j];
				strength_order[j] = strength[i]; // 이거 하면서 아예 pairs 배열도 바꿔줬으면 하는데..?
				pairs[i] = pairs_copy[j];
				pairs[j] = pairs_copy[i];
				//pairs[i] = pairs_copy[j];
			}

		}
		//printf("strength of ordered pairs[%i] is = %i\n", i, strength_order[i]);
	}
    printf("after aligning _ strength[0] : %i, strength[1] : %i, strength[2] : %i\n", strength[0], strength[1], strength[2]);
    printf("after aligning _ strength_order[0] : %i, strength_order[1] : %i, strength_order[2] : %i\n", strength_order[0], strength_order[1], strength_order[2]);
    printf("\nafter aligning _ \npairs[0].winner&loser : %i(name:%s)&%i(name:%s) \t %i \npairs[1].winner&loser : %i(name:%s)&%i(name:%s)\t %i \npairs[2].winner&loser : %i(name:%s)&%i(name:%s) \t %i\n", pairs[0].winner, candidates[pairs[0].winner], pairs[0].loser, candidates[pairs[0].loser], strength_order[0], pairs[1].winner, candidates[pairs[1].winner], pairs[1].loser, candidates[pairs[1].loser],strength_order[1], pairs[2].winner, candidates[pairs[2].winner], pairs[2].loser, candidates[pairs[2].loser], strength_order[2] );
	/*
	for (int i = 0; i < pair_count; i++)
	{
    	for (int k = 0; k < pair_count; k++)
    	{
    		if (strength_order[i] == strength[k])
    		{
    			pairs[i] = pairs_copy[k];
    			//strength[k] = 0; // 중복방지를 위한 0으로 초기
    		}
    	}
        //printf("%i\t : strength of original pairs[%i]\n", strength[i], i);
        //printf("%i\t : strength of aligned pairs[%i]\n", strength_order[i], i);

	}
	*/
    return;
}
/*
void lock_pairs(void)
{
	string losers[pair_count];
	locked[pairs[0].winner][pairs[0].loser] = true;
	losers[0] = candidates[pairs[0].loser];
	for (int i = 1; i < pair_count; i++)
	{
		int j = 0;
		while (j < i)
		{
			if (candidates[pairs[i].winner] != losers[j])
			{
				locked[pairs[i].winner][pairs[i].loser] = true;
				losers[i] = candidates[pairs[i].loser];
				break;
			}
			else
			{
				locked[pairs[i].winner][pairs[i].loser] = false;
				j++;
			}
		}
	}
}
*/
//2020.05.05
void lock_pairs(void)
{
    for (int i = 0; i < pair_count ; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        printf("<before> locked[pairs[%i].winner][pairs[%i].loser] = locked[%i][%i]]\t boolean : %i\n", i, i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);

        for(int j = 0; j < i; j++)      // cycle 검사를 위한 반복 조건문
        {
            if ((locked[pairs[i].winner][pairs[j].winner] == true) && (i > (candidate_count-1)*(candidate_count-2)/2))
            {
            	locked[pairs[i].winner][pairs[i].loser] = false;
            }
        }

        printf("<after> locked[pairs[%i].winner][pairs[%i].loser] = locked[%i][%i]]\t boolean : %i\n", i, i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);
    }
    return;
}
/*
//2020.05.04
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    locked[pairs[0].winner][pairs[0].loser] = true;
    locked[pairs[1].winner][pairs[1].loser] = true;
    string losers[pair_count];
    losers[0] = candidates[pairs[0].loser];
    losers[1] = candidates[pairs[1].loser];
    for (int i = 2; i < pair_count ; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        printf("<before> locked[pairs[%i].winner][pairs[%i].loser] = locked[%i][%i]]\t boolean : %i\n", i, i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);
        for(int j = 0; j < i; j++)      // cycle 검사를 위한 반복 조건문
        {
            //if (candidates[pairs[i].winner] == losers[j])
            if (strcmp(candidates[pairs[i].winner],losers[j]) == 0)
            {
                locked[pairs[i].winner][pairs[i].loser] = false;
            }
        }
        if (locked[pairs[i].winner][pairs[i].loser] == true)
        {
            losers[i] = candidates[pairs[i].loser];
        }
        printf("<after> locked[pairs[%i].winner][pairs[%i].loser] = locked[%i][%i]]\t boolean : %i\n", i, i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);
	    printf("losers[%i] : %s\n", i, losers[i]);
	    //printf("index changed : [%i][%i] = [%s][%s]\n", pairs[i].winner, pairs[i].loser, candidates[pairs[i].winner], candidates[pairs[i].loser]);
    }
    return;
}
*/
/*//2020.04.30
void lock_pairs(void)
{
	string losers[pair_count];
	locked[pairs[0].winner][pairs[0].loser] = true;
	losers[0] = candidates[pairs[0].loser];
    int i = 1;
	while(i < pair_count)
	{
	    locked[pairs[i].winner][pairs[i].loser] = true;
	    losers[i] = candidates[pairs[i].loser];
		for (int j = 0; j < i; j++)
		{
			if (candidates[pairs[i].winner] == losers[j])
			{
				locked[pairs[i].winner][pairs[i].loser] = false;
			}
		}
	printf("index changed : [%i][%i] = [%s][%s]\n", pairs[i].winner, pairs[i].loser, candidates[pairs[i].winner], candidates[pairs[i].loser]);
	i++;
	}
    return;
}
*/
/*
void lock_pairs(void)
{
	//int winners[pair_count];
    string losers[pair_count];
	//int locked_count = 0;
	locked[pairs[0].winner][pairs[0].loser] = true;
	losers[0] = candidates[pairs[0].loser];
    for (int i = 1; i < pair_count; i++)
    {
    	for (int j = 0; j < i; j++)
    	{
    	    int check = strcmp(candidates[pairs[i].winner],losers[j]);
	    	if ( check != 0) // 이 조건에서 [2][0]이 계수가 안됨
	    	{
	    		locked[pairs[i].winner][pairs[i].loser] = true;
	    		losers[i] = candidates[pairs[i].loser];
	    		printf("\nwhich plots are locked?\n");
	    		//printf("'true' changed : [pairs[%i].winner][pairs[%i].loser] : [%i][%i]\n",i,i,pairs[i].winner, pairs[i].loser  );
	    		printf("index changed : [%i][%i] = [%s][%s]\n", pairs[i].winner, pairs[i].loser, candidates[pairs[i].winner], candidates[pairs[i].loser]);
	    		//winners[i] = pairs[i].winner;
	    		//locked_count++;
	    	}
	    }
    	//winners[i] = pairs[i].winner;
    }
    return;
}
*/

/* 조건은 다 맞는 코드..
void lock_pairs(void)
{
	//int winners[pair_count];
	//int losers[pair_count];
	//int locked_count = 0;
    for (int i = 0; i < pair_count; i++)
    {
        printf("<before> locked[pairs[%i].winner][pairs[%i].loser] = locked[%i][%i]]\t boolean : %i\n", i, i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);
    	if (pairs[i].loser != pairs[0].winner)  // 이 조건에서 [2][0]이 계수가 안됨
    	{
    		locked[pairs[i].winner][pairs[i].loser] = true;
    		//printf("index changed : [%i][%i]\n", pairs[i].winner, pairs[i].loser);
    		//winners[i] = pairs[i].winner;
    		//locked_count++;
    	}
    	printf("<after> locked[pairs[%i].winner][pairs[%i].loser] = locked[%i][%i]]\t boolean : %i\n", i, i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);
    	//winners[i] = pairs[i].winner;
    }
    return;
}
*/

/*
void lock_pairs(void)
{
	int winners[pair_count];
	//int losers[pair_count];
	int locked_count = 0;
    for (int i = 0; i < pair_count; i++)
    {
    	for (int j = 0; j <= locked_count; j++)
    	{
    		if (pairs[i].loser != winners[j])
    		{
    			locked[pairs[i].winner][pairs[i].loser] = true;
    			winners[i] = pairs[i].winner;
    			//locked_count++;
    		}
    	}
    	//winners[i] = pairs[i].winner;
    }
    return;
}
*/
/*
void lock_pairs(void)
{
	int winners[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
    	winners[i] = pairs[i].winner;
    	for (int j = 0; j < i; j++)
    	{
    		if (pairs[i].loser != winners[j])
    		{
    			locked[pairs[i].winner][pairs[i].loser] = true;
    		}
    	}
    }
    return;
}
*/

// Print the winner of the election
void print_winner(void)
{
	int true_count[candidate_count];
	for (int i = 0; i < candidate_count; i++)
	{
	    true_count[i] = 0;
	    //int false_count = 0;
		for (int j = 0; j < candidate_count; j++)
		{
		    if (locked[i][j] == true)
		    {
		    	true_count[i]++;
		    }
		}
		printf("true_count for %s is : %i\n", candidates[i], true_count[i]);
	}

    int maximum = 0;
	for (int j = 0; j < candidate_count; j++)
	{
	    if (true_count[j] > maximum)
        {
    	    maximum = true_count[j];
    	}
	}
	for (int j = 0; j < candidate_count; j++)
	{
	    if (maximum == true_count[j])
        {
            printf("%s\n", candidates[j]);
        }
	}
    return;
}
/*
void print_winner(void)
{
	winner_list[]
	loser_list[]
	for (int i = 0; i < candidate_count; i++)
	{
		for (int j = 0; j < candidate_count; j++)
		{
			if (i != j)
			{
				if (locked[i][j] == false)
				{
					break;
				}
			}
			else
			{
				printf("%s",candidates[i]);
			}
		}

	}
    return;
}
*/
/*
void print_winner(void)
{
	int losers[pair_count];
	int loser_count = 0;
	for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
            	loser_count++;
            	losers[loser_count] = pairs[i].loser;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        for (int k = 0; k < loser_count; k++)
	    {
	    	if (i != losers[k])
	    	{
	    		printf("%s",candidates[i]);
	    	}
	    }
    }
    return;
}
*/

