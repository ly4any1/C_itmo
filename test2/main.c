#include <stdio.h>
#include <math.h>
double comp=1e-300;
int main()
{
    double x,x1,x2,d,a=1,b=1e12,c=1e12;
    if((fabs(a)<=comp)&&(fabs(b)<=comp)&&(fabs(c)<=comp))
    {
        printf("+");
        goto M;
    }
    if((fabs(a)>=comp)&&(fabs(b)>=comp)&&(fabs(c)>=comp))
        goto D;
    if(fabs(a)<=comp)
    {
        if((fabs(b)>=comp)&&(fabs(c)>=comp))
        {
        printf("ne kvadratnoe\n");
        x = -c / b;
        printf("x=%g",x);
        goto M;
        }
        if((fabs(b)<=comp)&&(fabs(c)>=comp))
        {
            printf("error");
            goto M;
        }
        if((fabs(b)>=comp)&&(fabs(c)<=comp))
        {
            printf("x=0");
            goto M;
        }
    }
    if(fabs(b)<=comp)
    {
        if(c>comp)
        {
            printf ("net reshenyi");
            goto M;
        }
        if(fabs(c)<=comp)
        {
            x1 = sqrt(-c);
            if(fabs(x1)<=comp)
            {
                printf("x=0");
                goto M;
            }
            else
            {
                x2 = -sqrt(-c);
                printf("x1=%g\nx2=%g",x1,x2);
                goto M;
            }
        }
    }
    if (fabs(c)<=comp)
    {
        x1=0;
        x2=-b/a;
        printf("x1=%g\nx2=%g",x1,x2);
        goto M;
    }
    D:
    d=(pow(b,2)-4*a*c);
    if (d >=comp) {
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
        if(x1/x2==1)
        {
            x=x1;
            printf("x=%g\n",x);
            goto M;
        }
        else
            if(fabs(x1)<=comp)
            {
                x1=(c/a)/x2;
                printf("x1=%g\nx2=%g", x1, x2);
                goto M;
            }
            else
            {
                x2=(c/a)/x1;
                printf("x1=%g\nx2=%g", x1, x2);
                goto M;
            }
    }
    if (d < comp)
    {
        printf("net reshenyi");
    }
    M:
    return 0;
}