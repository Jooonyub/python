#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);        //to keep track of all of the preferences. If at any point, the ballot is deemed to be invalid, the program exits.
void tabulate(void);        //which should look at all of the voters’ preferences and compute the current vote totals, by looking at each voter’s top choice candidate who hasn’t yet been eliminated.
bool print_winner(void);     //should print out the winner if there is one; if there is, the program is over.
int find_min(void);         //otherwise, the program needs to determine the fewest number of votes anyone still in the election received
bool is_tie(int min);       //If it turns out that everyone in the election is tied with the same number of votes ,  the election is declared a tie
void eliminate(int min);    //otherwise, the last-place candidate (or candidates) is eliminated from the election

int main(int argc, string argv[])               // 후보자 이름 입력받기
{
    // Check for invalid usage
    if (argc < 2)                               // argument에 후보가 있어야.
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;                 // 후보 수는 argv[0]제외한 나머지
    if (candidate_count > MAX_CANDIDATES)       // 후보자 수 설정(최대 9명)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)   // **첫 for문_각 후보별 struct 생성
    {
        candidates[i].name = argv[i + 1];       // string name
        candidates[i].votes = 0;                // int votes
        candidates[i].eliminated = false;       // bool eliminated
    }

    voter_count = get_int("Number of voters: ");// 투표인 수 입력받기
    if (voter_count > MAX_VOTERS)               // 투표인 수 설정 (최대 100명)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)       // **두번째 for문_i : 투표자 루프
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)// **세번째 for문_j : 후보자 루프(pref & votes)
        {
            string name = get_string("Rank %i: ", j + 1);//i번째 투표자의 투표내용(모든 순위) 입력

            // Record vote, unless it's invalid
            if (!vote(i, j, name))              //vote라는 bool 실행
            {                                   //(써낸 이름이 후보와 일치하면 카운트, 다르면 invalid 메시지 표시&return)
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)     // i : #voter, j = #candidate(preference)
{                                               //candidate candidates.name(str) .votes(int) .eliminated(bool)
    for (int k = 0; k < candidate_count; k++)
    {
        if(strcmp(candidates[k].name, name) == 0)    /// 이름비교(candidates라는 2D Array의 [k].name와 j루프로 입력받은name)
        {
            preferences[voter][rank] = k;    //해당 후보에 대한 index값
            //candidates[rank].votes++        // 첫번째 preference에 해당하는 후보만 득표해야하지 않나..?
            return true;
        }
    }// TODO
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].eliminated == false)
        {
            candidates[j].votes++;
            printf("%i th preference candidate vote\n", j+1);
            printf("%s\n",candidates[j].name);
            printf("%i\n",candidates[j].votes);
            printf("\n");
        }
        /*else
        {
            candidates[[j+1]].votes++;
        }*/
    }// TODO
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int max_votes = 0;
    //string max_candidates[];
    string stdout;
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes > max_votes)
        {
            max_votes = candidates[j].votes;
            if (max_votes > (voter_count / 2))
            {
                stdout = candidates[j].name;
                printf("%s\n", stdout);
                return true;
            }
        }
    }
    // TODO
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count;
    for (int j = 0; j < candidate_count; j++ )
    {
        if (candidates[j].votes < min)
        {
            min = candidates[j].votes;
        }
    }
    // TODO
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int count = 0;
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == min)
        {
            count++;
            // for문 안에서 true가 한번이라도 선언되면 전체함수가 종료될까???
        }
    }
    if (count == candidate_count)
    {
        return true;
    }// TODO
    return false;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == min)
        {
            candidates[j].eliminated = true;
        }
    }// TODO
    return;
}
