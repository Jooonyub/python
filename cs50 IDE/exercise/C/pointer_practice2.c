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
    TRIPLEINT trinity[1][2];              //name : trinity      type : TRIPLEINT
    printf("Size of trinity is %lu\n", sizeof(trinity));
    trinity[0][0].a = 4;                  //name : trinity.a    type : int
    trinity[0][0].b = 7;                  //name : trinity.b    type : int
    trinity[0][0].c = 8;                  //name : trinity.c    type : int

    trinity[0][1].a = 87;                  //name : trinity.a    type : int
    trinity[0][1].b = 52;                  //name : trinity.b    type : int
    trinity[0][1].c = 36;                  //name : trinity.c    type : int

    //TRIPLEINT *p;                   //name : *p        type : TRIPLEINT *
    //p = &trinity;                   //name : p        type : address
    TRIPLEINT *p = &trinity[0][0];
    TRIPLEINT *p0 = p;
    TRIPLEINT *p1 = p + 1;
    TRIPLEINT *p2 = p + 2;

    printf("address of trinity is %p\n", p0);
    printf("address of trinity is %p\n", p+1);
    printf("address of trinity is %p\n", p+2);
    //printf("address of trinity - 3*sizeof 'trinity' is %p\n", p - 3);
    printf("address of TRUPLEINT *p1 is %p\n", p1);
    printf("address of trinity + 1*sizeof 'trinity' is %p\n", p1);
    printf("address of TRUPLEINT *p2 is %p\n", p2);
    printf("address of trinity + 2*sizeof 'trinity' is %p\n", p2);
    //printf("%d\n", p->b);

    //printf("before NULL\n");
    printf("using pointer position of p\n");
    printf("trinity.a = %d\n",p->a);
    printf("trinity.b = %d\n",p->b);
    printf("trinity.c = %d\n",p->c);
    //printf("trinity.b = %d\n",&(p+4));
    //printf("trinity.c = %d\n",&(p+8));

    printf("using components of p\n");
    printf("trinity.a = %d\n",trinity[0][0].a);
    printf("trinity.b = %d\n",trinity[0][0].b);
    printf("trinity.c = %d\n",trinity[0][0].c);

    printf("using pointer position of p+1\n");
    printf("trinity.a = %d\n",(p+1)->a);
    printf("trinity.b = %d\n",(p+1)->b);
    printf("trinity.c = %d\n",(p+1)->c);

    printf("using pointer position of p+1\n");
    printf("trinity.a = %d\n", p1->a);
    printf("trinity.b = %d\n", p1->b);
    printf("trinity.c = %d\n", p1->c);

    printf("using components of p+1\n");
    printf("trinity.a = %d\n",trinity[0][1].a);
    printf("trinity.b = %d\n",trinity[0][1].b);
    printf("trinity.c = %d\n",trinity[0][1].c);

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