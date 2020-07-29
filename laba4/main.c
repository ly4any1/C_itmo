#include <stdio.h>
#include <math.h>
int main()
{
    float x0,x1,dx,a,A,b,B,c,C,f,F;
    int count=0;
    scanf("%e%e%e", &x0,&x1,&dx);
    scanf("%e%e%e", &a,&b,&c);
    modff(a,&A);
    modff(b,&B);
    modff(c,&C);
    if((!(A||B)&&((long long)A^(long long)C))!=0)
        count=1;
    printf("\n");
    printf("┌───────────────────┬───────────────────┐\n");
    printf("│          x        │        f(x)       │\n");
    printf("├───────────────────┼───────────────────┤\n");
    for(float x=x0;x<=x1;x+=dx)
    {
        if((x<3)&&(b!=0))
            f=a*x-b*x-c;
        else if((x>6)&&(b==0))
            if((x-c)!=0)
            f=(x-a)/(x-c);
            else
                f=0;
        else
            if(c!=0)
            f=x/c;
            else
                f=0;
        if(count!=1)
        {
            modff(f,&F);
            printf("|%g\t\t\t|%.5e\t\t|\n",x,F);
        }
        else
            printf("|%g\t\t\t|%.5e\t\t|\n",x,f);
    }
    printf("└───────────────────┴───────────────────┘");
    printf("\n");
    return 0;
}
