#include <cs50.h>
#include <stdio.h>

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
    		ranks[j] = k;
    		return true;
    	}
    	else							//입력한 이름이 후보자 명단에 없는 경우
    	{
    		return false;
    	}
    }
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
    			preferences[[ranks[j]][ranks[k]]] = 0;
    		}
    		else if (j < k)					//j < k인 경우(해당하는 preference에 +1)
    		{
    			preferences[[ranks[j]][ranks[k]]]++;
    		}
    		// j > k인 경우는 성립하지 않으므로 패스
    	}
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
	pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
    	for (int j = 0; j < candidate_count; j++)
    	{
    		if (i != j)
    		{
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
    		}
    	}
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
	int strength[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
    	int strength[i] = preference[pairs[i].winner][pairs[i].loser] - preference[pairs[i].loser][pairs[i].winner];
    }

    pair pairs_sorted[pair_count];
	int sort_count = 0;
	for (int i = 0; i < pair_count; i++)
	{
		for (int j = i+1 ; j < pair_count; j++)
		{
			if (strength[i] < strength[j])	// 배열순서상 뒤에 위치한 index의 strength가 더 큰 경우
			{
				strength[i] = strength[j];
				sort_count++;
			}
		}
		pairs_sorted[i] = pairs[i + sort_count];
	}

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
	int winners[];
    for (int i = 0; i < pair_count; i++)
    {
    	winners[i] = pairs[i].winner;
    	for (int j = 0; j < i; j++)
    	{
    		if (pairs[i].loser != winner[j])
    		{
    			locks[[pairs[i].winner][pairs[i].loser]] = true;
    		}
    	}
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
	int losers[];
	int loser_count = 0;
	for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] == true)
            {
            	loser_count++;
            	losers[loser_count] = j;
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

