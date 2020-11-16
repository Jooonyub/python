#include <stdio.h>
//#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{

    /*
    BYTE buffer;
    typedef BYTE block = sizeof(buffer[512]);
    return 0;
    */

    BYTE *buffer;
	buffer block = malloc(sizeof 512*(BYTE));
	return 0;
}