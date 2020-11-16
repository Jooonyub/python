#include <stdio.h>

int main(void)
{
    //FILE *inptr = fopen("~/pset5/speller/texts/lalaland.txt", "r");
    FILE *inptr = fopen("test.txt", "r");
    if (inptr == NULL)
    {
        return 1;
    }
    char dicword[50];
    int count = 0;
    while(fscanf(inptr, "%s", dicword) != EOF)
    {
        printf("%s\n", dicword);
        count++;
    }
    printf("\ntotal words : %d",count);


    /*
    printf("%i\n",i);
    printf("%c\n",i);
    */
    fclose(inptr);
    return 0;
}