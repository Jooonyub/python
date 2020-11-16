#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
	if (argc == 2)
	{
		string key = argv[1];
		for (int i=0 ; key[i] != '\0' ; i++)
		{
			isdigit (key[i]);
			return 0;
		}

		string s = get_string("Plain Text : \n");
		for (int j = 0; s[j] != '\0'; j++)
		{
			isalpha(s[j]);
				isupper(s[j]);
				{
					printf("%c", (((int) s[j] + (int) key) % 25 + 65));
				}
				islower(s[j]);
				{
					printf("%c", (((int) s[j] + (int) key) % 25) + 97);
				}
			printf("%c", s[j]);
		}
	}

}

/*
isalpha()
isdigit()
isupper()
islower()
*/