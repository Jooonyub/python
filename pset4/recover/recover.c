#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

    FILE *inptr = fopen(infile, "r"); // 이거 왜하는거지?? 꼭 필요한가??
    //If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    BYTE buffer[512];
    //BYTE *buffer(512);
    //BYTE dupcheck[512]; // 중복된 jpg파일이 있는지 찾울 때 각각의 파일을 열어 이 Array에 저장하여 비교하도록 하자.
    //int block = 0; //굳이 필요 없을듯
    int i = 0; // jpg파일의 iteration용도
    int j = 0; // 중복이 될때마다 +1해주기 위한 변수
    char filename[sizeof("%03i.jpg")];
    //char dupcheck[sizeof("%03i.jpg")];
    while (fread(buffer, sizeof(buffer), 1, inptr) == 1)    //fread()의 결과값으로 1이 나오지 않는다면, 이는 분명 파일을 다 읽었음을 의미한다. 파일포인터에서 BYTE[512]크기만큼 buffer라는 char array에 읽어들임
    {
        //sprintf(filename, "%03i.jpg", i);
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0) // 'jpg 조건을 충족하는가?'jpg가 맞다면 이 조건문에 대해 참이 될 것
        {
            //char filename[sizeof("%03i.jpg")];
            sprintf(filename, "%03i.jpg", i);
            //FILE *img = fopen(filename, "w");
            if (i == 0) //첫번째 jpg파일인 경우 fopen부터 해줘야.
            {
                FILE *img = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
                fclose(img);
            }
            else //첫번째 jpg파일이 아닌 경우 fclose부터 해줘야.
            {
                FILE *img = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
                fclose(img);
            }
            i++;
        }
        else
        {
            if (i != 0)
            {
                FILE *img = fopen(filename, "a");
                fwrite(buffer, sizeof(buffer), 1, img);
                fclose(img);
            }
        }//jpg 조건을 충족하지 않는 경우
    }
    fclose(inptr);

}
