#include <cs50.h>
#include <stdio.h>

bool vote(int voter, int rank, string name);

int main(int argc, string argv[])
{


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
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //이미 후보자수에 대한 j루프 안에서 유저로부터 string name을 입력받은 상태
    if (name != candidates[j].name)
    {
        return false;
    }
    voter
}
