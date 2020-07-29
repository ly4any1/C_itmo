#include <stdio.h>
int main()
{
    struct stock_students
    {char full_name[30];
        char group [8];
        char scholarship [5];
        float price;
        char comment[40]; }
            current[4]={{"Simakov Kirill","N3150","Yes",1600},{"Gritsenko Andrey","N3150","No"},{"Leont'eva Polina","N3150","Yes",1600},{"Aslanova Nargiza","N3151","Yes",1600}};
    printf("%s\v%s\t%s\t%.2f\t\n",current[0].full_name,current[0].group,current[0].scholarship,current[0].price);
    printf("%s\v%s\t%s\v\n",current[1].full_name,current[1].group,current[1].scholarship);
    printf("%s\v%s\t%s\t%.2f\t\n",current[2].full_name,current[2].group,current[2].scholarship,current[2].price);
    printf("%s\v%s\t%s\t%.2f\t\n",current[3].full_name,current[3].group,current[3].scholarship,current[3].price);
    printf("\n");
    struct complex
    {double real;
        double image; }
            complex[3]={{1.5,3.3},{2.1,6.7},{0.0,0.0}};
    complex[2].real=complex[0].real+complex[1].real;
    complex[2].image=complex[0].image+complex[1].image;
    printf("%.2lf+%.2lfi\n",complex[2].real,complex[2].image);
    complex[2].real=complex[0].real*complex[1].real;
    complex[2].image=complex[0].image*complex[1].image;
    printf("%.2lf+%.2lfi\n",complex[2].real,complex[2].image);
    printf("\n");
    return 0;
}
