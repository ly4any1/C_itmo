#include <stdio.h>
void row1row2(int arr[][3],int,int,int,int);
void col1col2(int parr[][3],int,int,int,int);
int main()
{
    int arr[3][3]={{12,50,-2},{100,-75,5},{34,0,44}};
    for (int l=2;l>0;l--)
    {
        for(int i=0;i<l;i++)
        {
            int sum1=0,sum2=0;
            for(int j=0;j<3;j++)
            {
                sum1+=arr[i][j];
                sum2+=arr[i+1][j];}
            if (sum1>sum2)
                row1row2(arr,3,3,i,i+1);
        }
    }
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int l=2;l>0;l--)
    {
        for(int j=0;j<l;j++)
        {
            int sum1=0,sum2=0;
            for(int i=0;i<3;i++)
            {
                sum1+=arr[i][j];
                sum2+=arr[i][j+1];
            }
            if (sum1>sum2)
                col1col2(arr,3,3,j,j+1);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",arr[i][j]);
        printf("\n");}
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
