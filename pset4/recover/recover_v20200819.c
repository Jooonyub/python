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
    while (fread(buffer,sizeof(buffer),1,inptr) == 1)    //fread()의 결과값으로 1이 나오지 않는다면, 이는 분명 파일을 다 읽었음을 의미한다. 파일포인터에서 BYTE[512]크기만큼 buffer라는 char array에 읽어들임
    {
        /*
        - 512바이트 단위로 읽어들임
        해당 회차에 첫 4바이트가 jpg형식을 띌 경우
            쓰기모드의 ***.jpg파일 열기
            작성
            새로운 block의 첫 4바이트가 jpg형식을 띌때까지 -> 계속 이어서 쓰기. 새로운 jpg파일 형식을 발견한다면 fclose() 하고나서 i++한 sprintf() 입력해주고 다시 fopen 
        띄지 않을 경우
            패쓰
        
        */
        
        
        //sprintf(filename, "%03i.jpg", i);
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0) // 'jpg 조건을 충족하는가?'jpg가 맞다면 이 조건문에 대해 참이 될 것
        {
            //char filename[sizeof("%03i.jpg")];
            sprintf(filename, "%03i.jpg", i);
            FILE *img = fopen(filename, "w");
            fwrite(buffer,sizeof(buffer),1,img);
	        for (int k = 0; k < i; k++) // 변수 j는 0~i까지 차례차례 비교해보기 위한 count
	        {
	        	char dupcheck[sizeof("%03i.jpg")];
	            sprintf(dupcheck, "%03i.jpg", k);
	            FILE *cmp = fopen(dupcheck, "r");
	            if (memcmp(cmp,img,sizeof(buffer))==0)
	            {
	            	j++;
	            }
	        	fclose(cmp);
	        }
	        if (j == 0) // 중복되는게 없었음을 의미
	        {
	            i++;
	        }
	        //중복되는게 있음
	        fclose(img);
        }
        //jpg 조건을 충족하지 않는 경우
    }
    fclose(inptr);

}
