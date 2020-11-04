#include "helpers.h"
#include <stdio.h>
#include <math.h>

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp;
    printf("before swap : (%d , %d , %d)  (%d , %d , %d)\n", a->rgbtBlue, a->rgbtGreen, a->rgbtRed, b->rgbtBlue, b->rgbtGreen, b->rgbtRed);
    temp = *a;
    *a = *b;
    *b = temp;
    printf("after swap : (%d , %d , %d)  (%d , %d , %d)\n", a->rgbtBlue, a->rgbtGreen, a->rgbtRed, b->rgbtBlue, b->rgbtGreen, b->rgbtRed);
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int image_avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);
            image[i][j].rgbtBlue = image_avg;
            image[i][j].rgbtGreen = image_avg;
            image[i][j].rgbtRed = image_avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed; /*255/(.393 + .769 + .189));*/
            image[i][j].rgbtGreen = sepiaGreen; /*255/(.349 + .686 + .168));*/
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / (float)2 ; j++) // j의 범위를 width로 한다면 바꿨던 값들이 다시 원래의 값으로 복귀하는 현상이 있는데, 이를 방지키 위해 round(width/2)를 함
        {
            printf("a : image[%d][%d], b : image[%d][%d]\n", i, j, i, width - j);
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}


// Blur image
// 20200721-2 백업 Array 생성해서 접근 -> 성공!!
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *ptr = &image_copy[i][j];
            //printf("ptr is pointing at images[%d][%d]\n",i,j);
            RGBTRIPLE *p1 = ptr - width - 1;
            RGBTRIPLE *p2 = ptr - width;
            RGBTRIPLE *p3 = ptr - width + 1;
            RGBTRIPLE *p4 = ptr - 1;
            RGBTRIPLE *p5 = ptr;
            //printf("ptr이 가리키는 image[i][j]의 BGR값 : %d, %d, %d\n", p5->rgbtBlue, p5->rgbtGreen, p5->rgbtRed);
            RGBTRIPLE *p6 = ptr + 1;
            RGBTRIPLE *p7 = ptr + width - 1;
            RGBTRIPLE *p8 = ptr + width;
            RGBTRIPLE *p9 = ptr + width + 1;
            if (j == 0) // 대상 pixel이 array 맨 왼쪽의 pixel인 경우
            {
                if (i == 0) // 대상 pixel이 좌측 상단의 pixel(5689)
                {
                    printf("5689\n");
                    //printf("[%d][%d]\t[%d][%d]\n[%d][%d]\t[%d][%d]\n", i,j, i,j+1, i+1,j, i+1,j+1);
                    image[i][j].rgbtBlue = round((p5->rgbtBlue + p6->rgbtBlue + p8->rgbtBlue + p9->rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((p5->rgbtGreen + p6->rgbtGreen + p8->rgbtGreen + p9->rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((p5->rgbtRed + p6->rgbtRed + p8->rgbtRed + p9->rgbtRed) / 4.0);
                }
                else if (i == height - 1) // 대상 pixel이 좌측 하단의 pixel(2356)
                {
                    printf("2356\n");
                    image[i][j].rgbtBlue = round((p2->rgbtBlue + p3->rgbtBlue + p5->rgbtBlue + p6->rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((p2->rgbtGreen + p3->rgbtGreen + p5->rgbtGreen + p6->rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((p2->rgbtRed + p3->rgbtRed + p5->rgbtRed + p6->rgbtRed) / 4.0);
                }
                else // 대상 pixel이 좌측 중앙의 pixel(235689)
                {
                    printf("235689\n");
                    image[i][j].rgbtBlue = round((p2->rgbtBlue + p3->rgbtBlue + p5->rgbtBlue + p6->rgbtBlue + p8->rgbtBlue + p9->rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((p2->rgbtGreen + p3->rgbtGreen + p5->rgbtGreen + p6->rgbtGreen + p8->rgbtGreen + p9->rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((p2->rgbtRed + p3->rgbtRed + p5->rgbtRed + p6->rgbtRed + p8->rgbtRed + p9->rgbtRed) / 6.0);
                }
            }
            else if (j == width - 1) // 대상 pixel이 array 맨 오른쪽의 pixel인 경우
            {
                if (i == 0) // 대상 pixel이 우측 상단의 pixel(4578)
                {
                    printf("4578\n");
                    image[i][j].rgbtBlue = round((p4->rgbtBlue + p5->rgbtBlue + p7->rgbtBlue + p8->rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((p4->rgbtGreen + p5->rgbtGreen + p7->rgbtGreen + p8->rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((p4->rgbtRed + p5->rgbtRed + p7->rgbtRed + p8->rgbtRed) / 4.0);
                }
                else if (i == height - 1) // 대상 pixel이 우측 하단의 pixel(1245)
                {
                    printf("1245\n");
                    image[i][j].rgbtBlue = round((p1->rgbtBlue + p2->rgbtBlue + p4->rgbtBlue + p5->rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((p1->rgbtGreen + p2->rgbtGreen + p4->rgbtGreen + p5->rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((p1->rgbtRed + p2->rgbtRed + p4->rgbtRed + p5->rgbtRed) / 4.0);
                }
                else // 대상 pixel이 우측 중앙의 pixel(124578)
                {
                    printf("124578\n");
                    image[i][j].rgbtBlue = round((p1->rgbtBlue + p2->rgbtBlue + p4->rgbtBlue + p5->rgbtBlue + p7->rgbtBlue + p8->rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((p1->rgbtGreen + p2->rgbtGreen + p4->rgbtGreen + p5->rgbtGreen + p7->rgbtGreen + p8->rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((p1->rgbtRed + p2->rgbtRed + p4->rgbtRed + p5->rgbtRed + p7->rgbtRed + p8->rgbtRed) / 6.0);
                }
            }
            else // 대상 pixel이 중앙부에 있을때
            {
                if (i == 0) // 대상 pixel이 중앙 위 pixel일때(456789)
                {
                    printf("456789\n");
                    image[i][j].rgbtBlue = round((p4->rgbtBlue + p5->rgbtBlue + p6->rgbtBlue + p7->rgbtBlue + p8->rgbtBlue + p9->rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((p4->rgbtGreen + p5->rgbtGreen + p6->rgbtGreen + p7->rgbtGreen + p8->rgbtGreen + p9->rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((p4->rgbtRed + p5->rgbtRed + p6->rgbtRed + p7->rgbtRed + p8->rgbtRed + p9->rgbtRed) / 6.0);
                }
                else if (i == height - 1) // 대상 pixel이 중앙 아래 pixel일때(123456)
                {
                    printf("123456\n");
                    image[i][j].rgbtBlue = round((p1->rgbtBlue + p2->rgbtBlue + p3->rgbtBlue + p4->rgbtBlue + p5->rgbtBlue + p6->rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((p1->rgbtGreen + p2->rgbtGreen + p3->rgbtGreen + p4->rgbtGreen + p5->rgbtGreen + p6->rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((p1->rgbtRed + p2->rgbtRed + p3->rgbtRed + p4->rgbtRed + p5->rgbtRed + p6->rgbtRed) / 6.0);
                }
                else // 완전 중앙(123456789)
                {
                    printf("123456789\n");
                    image[i][j].rgbtBlue = round((p1->rgbtBlue + p2->rgbtBlue + p3->rgbtBlue + p4->rgbtBlue + p5->rgbtBlue + p6->rgbtBlue + p7->rgbtBlue + p8->rgbtBlue + p9->rgbtBlue) / 9.0);
                    image[i][j].rgbtGreen = round((p1->rgbtGreen + p2->rgbtGreen + p3->rgbtGreen + p4->rgbtGreen + p5->rgbtGreen + p6->rgbtGreen + p7->rgbtGreen + p8->rgbtGreen + p9->rgbtGreen) / 9.0);
                    image[i][j].rgbtRed = round((p1->rgbtRed + p2->rgbtRed + p3->rgbtRed + p4->rgbtRed + p5->rgbtRed + p6->rgbtRed + p7->rgbtRed + p8->rgbtRed + p9->rgbtRed) / 9.0);
                }
            }
        }
    }
    return;
}