#include <stdio.h>

int main()
{
    int file_size = 0;
    FILE *fp = fopen("card.raw", "rb");
    if (NULL == fp) // 해당 파일이 존재하지 않는 경우
    {
        printf("파일이 없습니다.\n");
        return 1;
    }
    else
    {
        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp);
        printf("파일 크기 : %d bytes\n", file_size);
        fclose(fp);
        return 0;
    }
}