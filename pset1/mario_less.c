#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h  = 0;
    while (0 >= h || 8 < h)
    {
        h = get_int("Height: ");
    }

    for (int i = 0 ; i < h ; i++)
    {
        for (int j = 0 ; j < h ; j++)
        {
            if (h - 1 - i > j)
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