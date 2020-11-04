/*
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = get_int("Height:");
    if (1 <= h && 8 >= h)
    {
        printf("Stored: %i",h);
    }

    for (int i = 0 ; i < h ; i++)
    {
        for (int j = 0 ; j < h ; j++)
        {
            if (h - 1 - i > j )
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    return 1;
}
*/




#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h  = 0;
    while (h <= 0 || h > 8)
    {
        h = get_int("Height: ");
    }
    //printf("Stored: %i\n",h);

    for (int i = 0 ; i < h ; i++)
    {
        for (int j = 0 ; j < h ; j++)
        {
            if (h - 1 - i > j )
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    return 1;
}