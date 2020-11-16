//Array : One variable of multiple values

#include <cs50.h>
#include <stdio.h>

float average(int length, int array[]);

int main(void)
{
    // Get number of scores
    int n = get_int("Number of Scores: ");
    // Get scores
    int scores[n];

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }

    // Print average
    printf("Average: %.1f\n", average(n, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (float) sum / (float) length;
}

    /*
    #1
        // Scores
        int score1 = 72;
        int score2 = 73;
        int score3 = 33;
        // Print average
        printf("Average: %i\n", (score1 + score2 + score3) / 3);

    #2
        // Scores
        int scores[3];
        scores[0] = 72;
        scores[1] = 73;
        scores[2] = 33;
        // Print average
        printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / 3);

    #3
    #include <cs50.h>
    #include <stdio.h>
    const int N = 3;  // global constant value N을 정함으로써 함수에 영향받지 않고 N은 언제나 3이라는 것을 알려줌
    int main(void)
    {
        // Scores
        int scores[N];
        scores[0] = 72;
        scores[1] = 73;
        scores[2] = 33;
        // Print average
        printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / N);
    }


    */
