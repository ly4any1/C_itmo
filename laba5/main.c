#include <stdio.h>
double f1(int);
int f2(void);
int f3(void);
int main()
{
    int (*pf)(void);
    double(*pf1)(int);
    pf=f2;
    pf();
    printf("\n");
    int (*pmas[])(void)={f2,f3};
    pmas[1]();

    for(int i=0;i<2;i++)
        pmas[i]();
    printf("\n");

    long mas[3]={(long)f1,(long)f2,(long)f3};
    pf=(long(*)())mas[1];
    pf();
    printf("\n");

    pf1=(double(*)(int))mas[0];
    pf1(25);
    printf("\n");
    printf("%lf", pf1(25));
    printf("\n");
    double h = pf1(25);

    int a=0xa1b2c3d4;
    int*pa=&a;
    unsigned short b=*((short*)pa);
    unsigned short c=*((short*)pa+1);
    printf("\n");
    printf("%x\n",a);

    *((short*)pa+1)=b;
    *((short*)pa)=c;
    printf("%x\n",b);
    printf("%x\n",c);
    printf("%x\n",a);
    printf("\n");
}
double f1(int a)
{
    double b = a;
    printf("double f1(int a)");
    /*if (!a) return ++b;
     else*/ return 1.0 / b;
}

int f2(void)
{
    printf("int f2(void)");
    return 200;
}

int f3(void)
{
    printf("int f3(void)");
    return 300;
}
