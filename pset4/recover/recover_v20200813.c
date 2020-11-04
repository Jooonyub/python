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
    BYTE dupcheck[512]; // 중복된 jpg파일이 있는지 찾울 때 각각의 파일을 열어 이 Array에 저장하여 비교하도록 하자.
    int block = 0;
    int i = 0;
    char filename[sizeof("%03i.jpg")];
    while (fread(buffer,sizeof(buffer),1,inptr) != 1)    //fread()의 결과값으로 1이 나오지 않는다면, 이는 분명 파일을 다 읽었음을 의미한다.
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0) // 'jpg 조건을 충족하는가?'jpg가 맞다면 이 조건문에 대해 참이 될 것
        {
            //jpg 조건을 충족하는 경우
            int j = 0;
	        for (int k = 0; k <=i; k++) // 변수 j는 0~i까지 차례차례 비교해보기 위한 count
	        {
	        	sprintf(filename, "%03i.jpg", k); //이렇게 되면 i가 증가하지 않아도 또다시 sprintf되는 에러가 예상됨
                FILE *img = fopen(filename, "r");
	        	if (memcmp(img,buffer, sizeof(buffer)) == 0)
	        	{
	        		j++;
	        	}
	        	fclose(img);
	        }
	        if (j == 0) // 중복되는게 없었음을 의미
	        {

                //char filename[sizeof("%03i.jpg")]; //sizeof라는 함수를 썼다는것은, 이 데이터의 크기에 대해 바이너리 속성으로 측정하려 하는 것이다.
                sprintf(filename, "%03i.jpg", i); //이렇게 되면 i가 증가하지 않아도 또다시 sprintf되는 에러가 예상됨
                FILE *img = fopen(filename, "w");
                memcpy(img, buffer, sizeof(buffer));
                fclose(img);
                i++;
	        }
	        //중복되는게 있음
        }
        //jpg 조건을 충족하지 않는 경우
    }
    fclose(inptr);

}
