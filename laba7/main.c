#include <stdio.h>
#include <stdlib.h>

int **pparr;

void ff1(int ***pint,int dim1,int dim2)
{
    *pint=(int**)calloc(dim1,sizeof(int*));
    for (int i=0;i<dim1;i++)
        (*pint)[i]=(int*)calloc(dim2,sizeof(int));
}

int ff2(void (*pff1)(int ***, int, int), int ***parr, int dim1, int dim2)
{
    pff1(parr,dim1,dim2);
    for (int i=0;i<dim1;i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            pparr[i][j]=2*i+5-j;
        }
    }
    return 1;
}

int main()
{
    int dim1=3;
    int dim2=4;
    void(*pff1)(int***,int,int);
    pff1=ff1;
    int (*pff2)(void(int***,int,int),int***,int,int);
    pff2=ff2;
    pff2(pff1,&pparr,dim1,dim2);
    for (int i=0;i<dim1;i++)
    {
        for (int j = 0; j < dim2; j++)
            printf("%d\t", pparr[i][j]);
        printf("\n");
    }
    for(int i=dim1-1;i>=0;i--)
    {
        free(pparr[i]);
    }
    free(pparr);
    return 0;
}
