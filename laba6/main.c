#include <stdio.h>
#include <stdlib.h>

void ff1(int **, int);
int ff2(void(int**,int),int**,int);
int *pparr;

int main()
{
    int dim1=10;
    void(*pff1)(int**,int);
    pff1=ff1;
    int (*pff2)(void(int**,int),int**,int);
    pff2=ff2;
    printf("%d\n",pff2(pff1,&pparr,dim1));
    free (pparr);
    return 0;
}

void ff1(int **pint,int dim1)
{
    *pint=(int*)malloc(dim1*sizeof(int));
}

int ff2(void(*pff1)(int**,int),int **parr,int dim1)
{
    pff1(parr,dim1);
    for (int i=0;i<dim1;i++)
        pparr[i]=i*i+1;
    return pparr[8];
}
