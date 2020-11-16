#include <stdio.h>

int main(void)
{
    //FILE *inptr = fopen("~/pset5/speller/texts/lalaland.txt", "r");
    FILE *inptr = fopen("test.txt", "r");
    if (inptr == NULL)
    {
        return 1;
    }
    while(1)
    {
        int i = fgetc(inptr);
        if (i == EOF)
        {
            printf("\n");
            break;
        }
        else if (i == ' ')
        {
            printf("\n");
        }
        else
        {
            printf("%c",i);
        }

    }
    /*
    printf("%i\n",i);
    printf("%c\n",i);
    */
    fclose(inptr);
    return 0;
}
