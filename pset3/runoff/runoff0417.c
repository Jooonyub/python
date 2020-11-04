#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];                                //투표자수x후보수 만큼의 multi-dimentsional array 생성

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;                                                                  //name이라는 string, votes라는 int, eliminated라는 bool타입 세개묶음의 candidate 이름의 struct로 선언

// Array of candidates
candidate candidates[MAX_CANDIDATES];                                       //max vandidates수만큼의 candidate로 이루어진 1 dimensional array 생성

// Numbers of voters and candidates                                         //two global variables
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)                                                           // 후보자가 아무도 없는 경우 처음으로
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;                                             //입력한 command line arguement 토대로 candidate_count 선언
    if (candidate_count > MAX_CANDIDATES)                                   //최대 입후보수를 넘어설경우 처음으로
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)                               //candidates라는 'candidate'자료형의 index마다 후보이름argv[i+1], 득표수(0) , 탈락여부(false) 초기화
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");                            //사용자로부터 voter 수 입력
    if (voter_count > MAX_VOTERS)                                           //voter_count가 투표자 수 최대치보다 넘어설 경우 처음으로
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)                                   //루프시작(유권자별)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)                           //루프시작(순위(=후보자 수)별)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))                                          //➀입력값 타당성조사 -> 타당치 않을 경우 처음으로
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)                                                            //기본적으로 루프 계속 돌게 설정
    {
        // Calculate votes given remaining candidates
        tabulate();                                                         //➁유효 후보자 득표집계

        // Check if election has been won
        bool won = print_winner();                                          //➂print_winner에 true값 나오면 종료
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();                                               //➃유효후보중 최저득표자 인원수 도출
        bool tie = is_tie(min);                                             //최저득표자가 한명인지 확인(true면 복수, false면 1명)

        // If tie, everyone wins
        if (tie)                                                            //최저득표자가 복수일 경우
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)                              //유효후보일 경우 당선자 선언
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);                                                     //➅유효후보중 최저득표자 탈락(eliminated로 되어있는 bool 변경)

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)                           //유효후보별 득표수 초기화(=0)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int k = 0 ; k < candidate_count;k++)
    {
    	preferences[voter][rank] = 0;             // index 초기화
    	if (strcmp(candidates[k].name, name) == 0)        //입력한 name이 candidate 안에 있는지 확인
    	{
    		preferences[voter][rank] = k+1 ;
    	}
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
	for (int i = 0; i < voter_count; i++)                                   //루프시작(유권자별)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)                           //루프시작(순위(=후보자 수)별)
        {
        	if (candidates[preferences[i][j]].eliminated == false)
        	{
        		candidates[preferences[i][j]].votes++;
        	}
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int j = 0; j < candidate_count; j++)
    {
    	if (candidates[j].votes > (voter_count/2))
    	{
    		printf("%s\n", candidates[j].name);
    		return true;
    	}
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minimum_vote = MAX_VOTERS;
    for (int j = 0; j < candidate_count ; j++)
    {
    	if (candidates[j].votes <= minimum_vote)
    	{
    		minimum_vote = candidates[j].votes;
    	}
    } // TODO
    return minimum_vote;                                            // return 0; 을 해야하나..?
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int count_min = 0;												//최저득표자의 수를 파악키 위한 변수.(0으로 초기화)
    for (int j = 0; j < candidate_count; j++)
    {
    	if (candidates[j].votes == min)								//각 후보마다 최저득표수와 비교
    	{
    		count_min++;											//해당 후보의 득표수 = 최저득표수 이면 count값을 + 1
    	}
    }
    if (count_min == candidate_count)								//후보자수에 대한 루프를 돌리고 나서 최저득표자 인원과 전제후보인원이 같을 경우 완전히 동률이라고 간주
    {
    	return true;
    }
    else
    {
    	return false;
    }
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)											//eliminate에서 쓰이는 parameter : min(최저득수)
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