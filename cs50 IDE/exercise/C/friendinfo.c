//Do it! C언어 입문 18장 구조체와 연결리스트(2/2)
//친구 정보 관리 프로그램

/*
친구의 이름, 나이, 키, 몸무게를 받아서 입력하는 프로그램 작성
1. 작업 메뉴 : main 함수에서 처리
    사용자가 프로그램에서 제공하는 기능을 선택할 수 있도록 메뉴를 출력
2. 친구 추가하기 : AddFriend 함수에서 처리
    scanf 표준 입력 함수를 사용하여 한번에 1명씩 최대 5명까지 입력 받음
3. 친구 목록 보기 : ShowFriendList 함수에서 처리
    현재 입력된 친구 목록을 출력
*/


#include <stdio.h>

typedef struct
{
    char name[20];
    int age;
    float height;
    float weight;
} person;


person People[5];
int count;
void AddFriend(int index);
void ShowFriendList();


int main(void)
{
    count = 0;

    while (1)
    {
        int input;
        printf("===============\n");
        printf("1. 친구 추가\n");
        printf("2. 친구 목록 보기\n");
        printf("3. 종료\n");
        printf("===============\n");
        printf("번호 선택 : ");
        scanf("%d",&input);

        if (input == 1)
        {
            if (count < 5)
            {
                AddFriend(count);
                count++;
            }
            else
            {
                printf("최대 인원을 초과하여 입력을 할 수 없습니다.\n");
                printf("최대 %d명 까지만 관리 가능합니다\n", count);
            }
        }
        else if (input == 2)
        {
            ShowFriendList();
        }
        else if (input == 3)
        {
            break;
        }
        else
        {
            printf("번호를 잘못 입력하셨습니다. 다시 입력해주세요\n");
        }
    }


}

void AddFriend(int index)
{
    printf("\n");
    printf("1. 이름 : ");
    scanf("%s", People[index].name);
    printf("2. 나이 : ");
    scanf("%d", &People[index].age);
    printf("3. 키 : ");
    scanf("%f", &People[index].height);
    printf("4. 몸무게 : ");
    scanf("%f", &People[index].weight);
    printf("입력을 완료했습니다.\n");
}

void ShowFriendList()
{
    printf("\n");
    printf("등록된 친구 목록\n");
    printf("==============================\n");
    for (int j = 0; j < count; j++)
    {
        printf("%s\t, \t%d,\t%f,\t%f\n",People[j].name,People[j].age,People[j].height,People[j].weight);
    }
    printf("==============================\n");
}


/*
https://www.youtube.com/watch?v=Q8OT_EdYMEo&t=184s
여기서는 
AddFriend, 
ShowFriendList
에 각각 두개의 인자(Person *p, int count)를 써가는 식으로 작성했음을 알 수 있음
*/