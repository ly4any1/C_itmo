#include <stdio.h>
void row1row2(int arr[][3],int,int,int,int);
void col1col2(int parr[][3],int,int,int,int);
int main()
{
    int mas[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            mas[i][j]=8+2*i+j;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",mas[i][j]);
        printf("\n");
    }
    printf("\n");
    int max=mas[0][0];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(mas[i][j]>=max)
                max=mas[i][j];
        }
    printf("max=%d\n",max);
    printf("\n");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(i==j)
                mas[i][j]=max;
        }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",mas[i][j]);
        printf("\n");
    }
    printf("\n");
    int tmp=0,mas1[]={4,5,-11,0,-1,16,2,10};
    for(int i=7;i>0;i--)
    {
        int count=0;
        for(int j=0;j<i;j++)
            if(mas1[j]>mas1[j+1])
            {
                tmp=mas1[j];
                mas1[j]=mas1[j+1];
                mas1[j+1]=tmp;
                count++;
            }
        if(count==0)
            break;
    }
    for(int i=0;i<8;i++)
        printf("%d ", mas1[i]);
    printf("\n\n");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if((i==0 && j==2)||(i==2 && j==0))
                mas[i][j]=max;
        }
    mas[2][1]=155;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",mas[i][j]);
        printf("\n");
    }
    printf("\n");
    int tmp1=0;
    for(int i=0;i<3;i++)
    {
        tmp1=mas[0][i];
        mas[0][i]=mas[2][i];
        mas[2][i]=tmp1;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",mas[i][j]);
        printf("\n");
    }
    printf("\n");
    row1row2(mas,3,3,0,1);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",mas[i][j]);
        printf("\n");
    }
    printf("\n");
    col1col2(mas,3,3,1,2);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",mas[i][j]);
        printf("\n");
    }
    printf("\n");
    int imax=0,jmax=0,max1=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(mas[i][j]>max1)
            {
                max1=mas[i][j];
                imax=i;
                jmax=j;
            }
    row1row2(mas,3,3,imax,0);
    col1col2(mas,3,3,jmax,2);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",mas[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}
void row1row2(int arr[][3],int dim1,int dim2,int row1,int row2)
{
    int tmp1;
    for(int i=0;i<dim1;i++)
    {
        tmp1=arr[row1][i];
        arr[row1][i]=arr[row2][i];
        arr[row2][i]=tmp1;
    }
}
void col1col2(int parr[][3],int dim1,int dim2,int col1,int col2)
{
    int tmp1;
    for(int i=0;i<dim2;i++)
    {
        tmp1=parr[i][col1];
        parr[i][col1]=parr[i][col2];
        parr[i][col2]=tmp1;
    }
}
