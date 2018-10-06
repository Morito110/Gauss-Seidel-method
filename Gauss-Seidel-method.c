#include<stdio.h>

double a1,a2,a3,b1,b2,b3,c1,c2,c3;
double a,b,c;

double get_x1 (double x2, double x3)
{
    return( (a - a2*x2 - a3*x3 ) / a1);
}

double get_x2 (double x1, double x3)
{
    return( (b - b1*x1 - b3*x3 ) / b2);
}

double get_x3 (double x1, double x2)
{
    return( (c - c1*x1 - c2*x2 ) / c3);
}

int main()
{
    printf("3x3の行列に限るとする\n");

/***************************************/
    printf("a1: a2: a3: \n");
    scanf("%lf %lf %lf", &a1, &a2, &a3);
    printf("b1: b2: b3: \n");
    scanf("%lf %lf %lf", &b1, &b2, &b3);
    printf("c1: c2: c3: \n");
    scanf("%lf %lf %lf", &c1, &c2, &c3);
/***************************************/

    printf("a: b: c: \n");
    scanf("%lf %lf %lf", &a, &b, &c);

/***************************************/

    int i;
    double x1,x2,x3;

    printf("x1: x2: x3:\n");
    scanf("%lf %lf %lf", &x1, &x2 ,&x3);

    printf("\n\nround 0 , x1:%f, x2:%f, x3:%f\n" , x1, x2, x3);

    for(i = 1; i<20; i++)
    {
        printf("round %d ,", i);

        x1 = get_x1( x2, x3);
        x2 = get_x2( x1, x3);
        x3 = get_x3( x1, x2);
        printf(" x1:%f, x2:%f, x3:%f\n", x1, x2, x3);
    }
}
