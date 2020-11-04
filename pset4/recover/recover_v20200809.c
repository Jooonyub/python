#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    //sprintf(filename, "%03i.jpg", 2);
    //FILE *img = fopen(filename, "w");
    /////20200722 18:03 ///// 일단 여기까지
    BYTE buffer[512];
    int block = 0;
    //int num = 0;
    char filename[sizeof("%03i.jpg")];
    while (fread(img,sizeof(buffer),1,inptr) != 1)    //fread()의 결과값으로 1이 나오지 않는다면, 이는 분명 파일을 다 읽었음을 의미한다.
    //while (fread(img,sizeof(buffer),1,inptr) != 1) 단위 분할을 잘 해야겠는데..? 일단 block 크기의 단위로 쪼개고, 그 다음에는 [0], [1]
    //fread(filename,sizeof(buffer),1,infile);  바로 윗줄의 코드와 지금 이 코드는 어떤 점이 다른걸까?
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0) // jpg가 맞다면 이 조건문에 대해 참이 될 것
        {
            int j = 0;
	        for (int k = 0; k <=i; k++) // 변수 j는 0~i까지 차례차례 비교해보기 위한 count
	        {
	        	if (strcmp(k번째 jpg파일,이번 회차에 입력된 buffer) == 1)
	        	{
	        		j++;
	        	}
	        }
	        if (j == 0); // 중복되는게 없었음을 의미
	        {
	            sprintf(filename, "%03i.jpg", i); //이렇게 되면 i가 증가하지 않아도 또다시 sprintf되는 에러가 예상됨
                FILE *img = fopen(filename, "w");
	        }
        }


/////2020.08.06/////
    }
    /////20200730 18:03 ///// 일단 여기까지
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
