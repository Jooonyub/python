#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        for (int i = 0 ; argv[1][i] != '\0' ; i++)
        {
            if (isdigit(argv[1][i]) == 0)   // when the character is not numeric
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
            else                            // When the character is numeric
            {
                string key = argv[1];
                string s = get_string("plaintext: ");
                printf("ciphertext: ");
                for (int j=0 ; s[j] != '\0' ; j++)
                {
                    if (isalpha(s[j]) != 0)
                    {
                        if (isupper(s[j]) != 0)
                        {
                            printf("%c", ((/*(int)*/s[j] + atoi(key)-65)%26 + 65));
                        }
                        else
                        {
                            printf("%c", ((/*(int)*/s[j] + atoi(key)-97)%26 + 97));
                        }
                    }
                    else
                    {
                        printf("%c", s[j]);
                    }
                }
                printf("\n");
                return 0;

            }
        }
    }
}