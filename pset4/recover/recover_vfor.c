#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid. Usage : ./recover image");
        return 1;
    }

    //OPEN MEMORY CARD
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    //If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.
    if (inptr == NULL)
    {
    		fprintf(stderr, "Could not open %s.\n", infile);
    		return 1;
    }
    //sprintf(filename, "%03i.jpg", 2);
    //FILE *img = fopen(filename, "w");
    /////20200722 18:03 ///// 일단 여기까지
    int num = 1;
    char filename[sizeof("%03i.jpg")];
    while (true)    //반복문 설정을 for문으로 할 것인가 while문으로 할 것인가??
    {
        for (int i = 1, i < 
        {
            sprintf(filename, "%03i.jpg", i); // filename을 여기서 선언해도 되는건가?
            FILE *img = fopen(filename, "w");
        }
    }
    
        /*
        FILE *file = fopen(argv[1],"r");
            //1 buffer = 1 byte
            //1 block = 512 buffers
        //REPEAT UNTIL END OF CARD
        //READ 512 BYTES INTO A BUFFER
        BYTE buffer[512] = block
        //IF START OF NEW JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            //IF FIRST JPEG
            //ELSE
            sprintf(filename, "%03i.jpg", 2);
            FILE *img = fopen(filename, "w");
        }
        //ELSE(IF ALREADY FOUND JPEG)
        */
    }

    //CLOSE ANY REMAINING FILES
}
