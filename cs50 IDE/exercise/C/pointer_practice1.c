#include <stdio.h>

typedef struct
{
    int a;
    int b;
    int c;
}
TRIPLEINT;

int main(void)
{
    TRIPLEINT trinity;              //name : trinity      type : TRIPLEINT
    printf("Size of trinity is %lu\n", sizeof(trinity));
    trinity.a = 4;                  //name : trinity.a    type : int
    trinity.b = 7;                  //name : trinity.b    type : int
    trinity.c = 8;                  //name : trinity.c    type : int

    //TRIPLEINT *p;                   //name : *p        type : TRIPLEINT *
    //p = &trinity;                   //name : p        type : address
    TRIPLEINT *p = &trinity;
    TRIPLEINT *p1 = p + 1;
    TRIPLEINT *p2 = p + 2;

    printf("address of trinity is %p\n", p);
    printf("address of trinity is %p\n", p+1);
    printf("address of trinity is %p\n", p+2);
    //printf("address of trinity - 3*sizeof 'trinity' is %p\n", p - 3);
    printf("address of TRUPLEINT *p1 is %p\n", p1);
    printf("address of trinity + 1*sizeof 'trinity' is %p\n", p1);
    printf("address of TRUPLEINT *p2 is %p\n", p2);
    printf("address of trinity + 2*sizeof 'trinity' is %p\n", p2);
    printf("%d\n", p->b);

    //printf("before NULL\n");
    printf("using pointer position\n");
    printf("trinity.a = %d\n",p->a);
    printf("trinity.b = %d\n",p->b);
    printf("trinity.c = %d\n",p->c);
    //printf("trinity.b = %d\n",&(p+4));
    //printf("trinity.c = %d\n",&(p+8));

    printf("using components\n");
    printf("trinity.a = %d\n",trinity.a);
    printf("trinity.b = %d\n",trinity.b);
    printf("trinity.c = %d\n",trinity.c);

    /*
    trinity = NULL;
    printf("after NULL\n");
    printf("trinity.a = %d\n",trinity.a);
    printf("trinity.b = %d\n",trinity.b);
    printf("trinity.c = %d\n",trinity.c);
    */
    return 0;
}

//p라는 TRIPLEINT pointer은 12바이트의 자리를 차지한다. 따라서 p에 1씩 증가하게되면 12바이트씩 차이를 두게 된다.