#include <cs50.h>
#include <stdio.h>

bool print_winner(void);

int main(int argc, string argv[])
{
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
        if (tie)                                                            //➄최저득표자가 복수일 경우
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)                              //유효후보일 경우 당선자 선언
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;                                                  // 이 브레이크는 candidate의 득표수가 동률일 경우 이름은 선언해주고 마치게 된다.
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

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //TODO
    return false;
}