//pset2 _ substitution
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    while (argc != 2)                                   //arguement vector가 2개가 아닌 경우
    {
        printf("Usage : %s %s\n", argv[0], key);
        return 1;
    }

    if ((strlen(key) != 26) || (isalpha(key) != 0))                             //argv[1] 이 26자리가 아니거나, 한번씩 입력이 안됐거나, 알파벳이 아닐 때
    {
        printf("Usage : %s %s\n", argv[0], key);
        return 1;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)                                //겹침 방지용 내장루프(key값이 중복되었을 때 다시 입력하게 하는 부분)
            {
                if ((i != j) && (tolower(key[i]) == tolower(key[j])))
                {
                    printf("Usage : %s %s\n", argv[0], key);
                    return 1;
                }
            }
        }
        // key에 대해 cipher에 제대로 연동되게끔 알맞게 변경하기
        int mapkey[26];
        for (int i = 0; i < 26; i++)                                    //key를 mapkey에 입력할 때 전부 대문자화하기
        {
            if (islower(key[i]) == 0)
            {
                key[i] = tolower(key[i]);
            }
        mapkey[i] = key[i] - 65;                                   //mapkey에는 해당 알파벳이 얼만큼의 갭이 있는지 기록한다.(0~25의 수가 있는 array)
        }
        //이제 유저로부터 pla\intext 받아내기
        string plaintext = get_string("plaintext : \n");
        string ciphertext [strlen(plaintext)];
        printf("ciphertext : ");
        for (int k = 0; k < strlen(plaintext); k++)
        {
            if (isalpha(plaintext[k]) == 0)
            {
                if (isupper(plaintext[k]) == 0)                 //0~25 사이의 숫자로 표현된 i번째 alphabet  (ex. 0번째 알파벳이 k(75)라면 plaintext의 A(65) 대신 + 10 을 더해주면 된다.)
                {
                    ciphertext[k] = (char)((int)plaintext[k] - mapkey[plaintext[k] - 65]);           //plaintext가 대문자일 경우
                }
                else
                {
                    ciphertext[k] = (char)((int)plaintext[k] - mapkey[plaintext[k] - 65] + 32);      //plaintext가 소문자일 경우
                }
            }
            printf("%s",ciphertext[k]);
        }
        printf("\n");
    }
    return 0;
}


/*
// 알파벳이 소문자 대문자를 막론하고 서로 겹치지 않았는지 확인하는 코드를 생각해보자..
앞에서 어떤 문자가 쓰였는지 하나하나 입력을 받아서 루프 속에서 해당 문자를 가려내는 방법
argv[1]은 총 26개의 index를 가지게 된다. (argv[0][0] ~ argv[0][25])
for (int i = 0; i < 26; i++)
{
    for (int j = 0; j < 26; j++)
    {
        if (i != j)
        {
            if (tolower(key[i]) == (tolower(key[j]))
            {

            }
        }
    }
}

//맵핑
mapkey는 차례대로 a~z까지를 나타낼 예정
key를 toupper()로 해서 A는 ㅁ, B는 ㅁ, ... 이런식으로 등호로 써주기

string mapkey[26];                                                      // ?? mapkey를 굳이 사용해야 할 이유가 있을까? 사용하게 된다면 multi dimensional array로 접근해야할것같은데, 안쓰는 방법도 있을듯..!
for (int i = 0; i < 26 ; i++)
{
    mapkey[i+1] = 65 + i;                                               //mapkey의 초기값 입력
    if (isupper(key[i]) == 0)                                           //대문자라면!
    {
        mapkey
    }
}



string plaintext = get_string("plaintext : \n");                        //입력text 받아내기

string ciphertext (strlen(plaintext));                                  //입력text만큼의 출력text 할당

printf("ciphertext : %s\n", plaintext);


만약에 입력문자가
1) ASCII 숫자범위 65~90 : 대문자.

2) ASCII 숫자범위 97~122 : 소문자

3) 그 외 : 그대로





--------------------------------------------------------------------------------------
    역순으로 생각을 해보기(실행과정이라고 여기고)
    프로그램이 실행되면 key 값을 command line arguement에 함께 입력해주어야 한다.
    그 다음으로 변환하고자 하는 문장을 입력하라고 뜰텐데, 내가 입력한 문장은 plain text라는 이름으로 입력이 될 것이다.
    이 문장에 대해 인덱스별 접근을 하게 된다.
for (int i = 0; i < strlen(plaintext); i++)
{

}
        1) if.. 이 plain text의 각각 index를 읽어들여서 우선 알파벳인지 아닌지 분별 - isalpha
        맞다면(0) => key 값으로 변경
if (isalpha(plaintext[i] == 0)
{
    if (isupper(plaintext[i] == 0))                 0~25 사이의 숫자로 표현된 i번째 alphabet  (ex. 0번째 알파벳이 k(75)라면 plaintext의 A(65) 대신 + 10 을 더해주면 된다.)
    {
        ciphertext[i] =
    }
}
        2) else.. 그대로 ciphertext로 옮기기
else
{
    ciphertext[i] = plaintext;
}



A(65) - Z(90)
a(97) - z(122)


********
0~25 사이의 숫자로 표현된 i번째 alphabet
(ex. 0번째 알파벳이 k(75)라면 plaintext의 A(65) 대신 + 10 을 더해주면 된다.)

어느 단계에서는 전부 대문자나 소문자로 변형해주어야 하고, 그 다음의 어느 단계에서는 다시 원상복귀를 시켜줘야 한다.
ex1) key값에 대해 한쪽으로 몰았다가, plaintext가 대문자인지 소문자인지 구별해서 각각 다른 식으로 변환해주는 방법
다른 방법은 뭐가있을까..... 근데 ex1)이 가장 깔끔해보일것같아서 일단 이걸로 도전!!


    <key에 대한 for 루프를 짤 때 넣어야 할 것 - mapkey>
int mapkey[strlen(key)];
mapkey[i] = int(key[i]) - 65             // 이 때 사용하는 key는 toupper를 통해 모두 대문자화되어있어야!

    <plaintext를 ciphertext로 변환할 때 넣어야 할 것>
ciphertext[i] = plaintext[i] + mapkey(int(plaintext[i]) - 65)           //plaintext가 대문자일 경우
ciphertext[i] = plaintext[i] + mapkey(int(plaintext[i]) - 65) + 32      //plaintext가 소문자일 경우


*/