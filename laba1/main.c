#include <stdio.h>
int main()
{
    printf ("Nikita Lychanyi\n");
    int x;
    scanf ("%d",&x);
    if (x&(x-1))
        printf ("NO\n");
    else
        printf ("YES\n");
    char mas[]="ITMO";
    char tmp;
    for (int i=0,j=3;i<2;i++,j--)
    {
        tmp=mas[i];
        mas[i]=mas[j];
        mas[j]=tmp;
    }
    printf("%s\n",mas);
    int count=0,i=0;
    while (mas[i++])
        count++;
    printf ("%d\n",count);
    return 0;
}