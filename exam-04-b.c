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

    int iter = 1;
    printf("\titer\ta\t\tb\t\tc\t\tfa\t\tfb\t\tfc\n");
    while (1)
    {
        double c = 0.5 * (a + b);
        double fa = f(a);
        double fc = f(c);
        double fb = f(b);
        printf("\t%d\t", iter);
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", a, b, c, fa, fc, fb);


        if (fabs(fc) <= epsilon)
        {
            printf("iteration: %d\n", iter);
            printf("x: %lf\n", c);
            printf("y: %lf\n", fc);
            break;
        }

        if (fa * fc > 0.0f) a = c;
        else  b = c;
        iter++;
    }

    return 0;
}
