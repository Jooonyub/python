#include <cs50.h>
#include <stdio.h>

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
    	preference[voter][rank] = 0;             // index 초기화
    	if (strcmp(candidates[k].name, name) == 0)        //입력한 name이 candidate 안에 있는지 확인
    	{
    		preference[voter][rank] = k+1 ;
    	}
    }
    for (int k = 0 ; k < candidate_count;k++)
    {
    	if (preference[voter][rank] == 0)
    	{
    		return false;
    	}
    }
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int j = 0; j < candidate_count; j++)                           //루프시작(순위(=후보자 수)별)
    {
        if (candidates[j].eliminated == 'false')                                          //➀입력값 타당성조사 -> 타당치 않을 경우 처음으로
        {
            candidates[j].votes++;
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int count = 0;
    for (int j = 0; j < candidate_count; j++)                           //루프시작(순위(=후보자 수)별)
    {
        if (candidates[j].votes > floor(candidate_count/2) + 1)                                          //➀입력값 타당성조사 -> 타당치 않을 경우 처음으로
        {
            count++;
        }
    }
/*과반수인 후보는 한명밖에 나올 수 없다. 이 한명이 나올 경우 print_winner은 true값을 내보내야 하는데.. 맨 마지막에 쓰여이ㅆ는 return false는 뭘까ㅠㅠ
    if (count != 1)
    {

    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // TODO
    return;
}
