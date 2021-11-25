#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS

double f(double x)
{
    return -3.0f * cosf(x);
}

int main()
{


    double a, b;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);

    double epsilon;
    printf("epsilon: ");
    scanf("%lf", &epsilon);

    while (1)
    {
        double c = 0.5 * (a + b);
        double fa = f(a);
        double fc = f(c);
        double fb = f(b);


        if (fabs(fc) <= epsilon)
        {
            printf("x: %lf\n", c);
            printf("y: %lf\n", fc);
            break;
        }

        if (fa * fc > 0.0f) a = c;
        else  b = c;

    }

    return 0;
}
