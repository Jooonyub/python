// Implements a list of numbers with an array of fixed size

#include <stdio.h>

int main(void)
{
    // List of size 3
    int list[3];

    // Initialize list with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Print list
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}


/*
[코드 해석] 2020.08.29

8       int라는 data type의 list라는 길이 3짜리 array 자료구조를 만든다.
11~13   각 요소별로 값을 넣어 초기화해준다.
16~19   for문을 이용, 각 리스트의 요소 값들을 출력해준다.

*/