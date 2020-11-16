#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{
    //자료형의 크기부터 먼저 파악하고 넘거가기
    printf("size of BYTE is : %lu\n", sizeof(BYTE));
    printf("size of char is : %lu\n", sizeof(char));
    printf("size of int is : %lu\n", sizeof(int));
    printf("size of float is : %lu\n", sizeof(float));
    printf("size of long is : %lu\n", sizeof(long));

    BYTE buffer[512];

    BYTE * block = (BYTE *)malloc(512*sizeof(BYTE));

    //block = buffer[512];
    //block = (BYTE *) malloc(512*sizeof(BYTE));
    printf("size of block is : %lu\n", sizeof(block));
    printf("size of block is : %lu\n", sizeof(buffer[512]));
    printf("size of buffer is : %lu\n", sizeof(buffer));
    return 0;
}
