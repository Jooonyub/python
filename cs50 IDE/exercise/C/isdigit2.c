// isdigit과 isalpha 실제로 해보는 예제
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int a, b;
	char c;
	a = 46;
	b = -4;
	c = 35;
	if (isdigit('a') != 0)
	{
		printf("number\n");
	}
	if (isdigit('b') != 0)
	{
		printf("number\n");
	}

	if (isalpha('a') != 0)
	{
		printf("alphabet\n");
	}
	if (isalpha("abc") != 0)
	{
		printf("alphabet\n");
	}

	return 0;
}
