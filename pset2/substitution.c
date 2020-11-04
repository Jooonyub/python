#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage : %s key\n", argv[0]);
        return 1;
    }
    else
    {
        string key = argv[1];
        if (strlen(key) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else                                        // 26자리 중 안되는 조건 필터
        {
            for (int i = 0; i < strlen(key); i++)
            {
                if (isalpha(key[i]) == 0)
                {
                    printf("Key must be only with alphabets.\n");
                    return 1;
                }
                else
                {
                    for (int j = 0; j < strlen(key); j++)
                    {
                        if (i != j)
                        {
                            if (toupper(key[i]) == toupper(key[j]))
                            {
                                printf("key should not repeat the same alphabet\n");
                                return 1;
                            }
                        }
                    }
                }
                key[i] = toupper(key[i]);
            }
        }
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int k = 0; k < strlen(plaintext); k++)
        {
            if (isupper(plaintext[k]) != 0)              //대문자일때
            {
                char ciphertext = key[(int)plaintext[k] - 65];
                printf("%c", ciphertext);
            }
            else if (islower(plaintext[k]) != 0)         //소문자일때
            {
                char ciphertext = key[(int)plaintext[k] - 97] + 32;
                printf("%c", ciphertext);
            }
            else                                        //문자가 아닐때
            {
                char ciphertext = plaintext[k];
                printf("%c", ciphertext);        // 혹시 %c 해놓고 뭐 해야하나..?
            }
        }
        printf("\n");
    }
    return 0;
}