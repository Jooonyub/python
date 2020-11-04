//pointer로 지정되어있는 file의 크기를 출력하는 연습코드

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");

    printf("size of card.raw is : %lu\n", sizeof(argv[1]));

    printf("size of card.raw is : %lu\n", sizeof(argv[0]));

    printf("size of card.raw is : %lu\n", sizeof(infile));

    printf("size of card.raw is : %lu\n", sizeof("card.raw"));
}