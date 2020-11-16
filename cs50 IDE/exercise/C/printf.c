
//반복문으로 printf 구현하기
/*
#include <stdio.h>

int main(void)
{
    for (int i = 0; i<5; i++)
    {
        printf("%03i.jpg\n",i);
    }
    return 0;
}
*/

//반복문으로 sprintf 구현하기
#include <stdio.h>

int main(void)
{
    char filename[sizeof("%03i.jpg")];
    for (int i = 0; i<5; i++)
    {
        sprintf(filename,"%03i.jpg\n",i); // 여기서 표현하고자 하는 filename이 몇이어야할까
        FILE *img = fopen(filename, "w");
        fwrite("과연", sizeof("과연"),1,img);
        fclose(img);
        //printf("size of 'filename' : %lu \t '%03i.jpg' : %lu \t '%03i' : %lu \n", sizeof(filename), i, sizeof("%03i.jpg"), i, sizeof('%03i'));
        printf("this time filename is %s\n", filename);
    }

    return 0;
}