//The Coleman-Liau index
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("text: ");
    int letters = 0;  // number of letters
    int words = 0;  // number of words
    int sentences = 0;  // number of sentences

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            letters++;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            letters++;
        }
        else
        {
            if (text[i] == 32)
            {
                words++;
            }
            else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
            {
                sentences++;
            }
        }
    }
    words = words + 1;

    //printf("Letters : %i\n",letters);
    //printf("Words : %i\n",words);
    //printf("Sentences : %i\n",sentences);

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    //printf("L : %f\n", L);
    //printf("S : %f\n", S);

    int Grade = round(0.0588 * L - 0.296 * S - 15.8);
    if (Grade >= 16)
    {
        printf("Grade 16+");
    }
    else if (Grade < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i", Grade);
    }
    printf("\n");
}