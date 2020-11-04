//Substitution cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        string key = argv[1];
        if (strlen(key) != 26)      // check if the key has 26 characters
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            for (int i = 0; i < strlen(key); i++)
            {
                if (isalpha(key[i]) == 0)   // when the character is not an alphabet
                {
                    printf("Key must contain alphabetic characters.\n");
                    return 1;
                }
                else
                {
                    for (int j = i+1; j < strlen(key); j++)
                    {
                        if (key[i] == toupper(key[j]) || key[i] == toupper(key[j]) + 32)
                        {
                            printf("Key must not contain repeated characters.\n");
                            return 1;
                        }
                    }
                    string s = get_string("plaintext: ");        //promt typing a plaintext from the user
                    printf("ciphertext: ");
                    for (int k =0; k < strlen(s); k++)
                    {
                        if (isupper(s[k]) != 0)                   //upper case print
                        {
                            int upperdif = s[k] - 65;
                            printf("%c", toupper(key[upperdif]));
                        }
                        else if (islower(s[k]) != 0)              //lower case print
                        {
                            int lowerdif = s[k] - 97;
                            printf("%c", tolower(key[lowerdif]));
                        }
                        else                                        //others print
                        {
                            printf("%c", s[k]);
                        }
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
}