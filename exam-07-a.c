#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

#define n_max 100

int n;
int mmax, mmin;
int mark[n_max];
char random_marks;
#define mmin 2
#define mmax 5
#define mpass 4.6f

int main()
{
    printf("Mark count: ");
    scanf("%d", &n);

    printf("Random marks?\nY/N: ");
    scanf("%s", &random_marks);

    if (random_marks == 'y' || random_marks == 'Y')
    {
        for (int i = 0; i < n; i++)
        {
            mark[i] = mmin + rand() % (mmax - mmin + 1);
            printf("%d ", mark[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Insert marks:");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &mark[i]);
            if (mark[i] < mmin)
            {
                printf("Error\n");
                return 0;
            }
            if (mark[i] > mmax)
            {
                printf("Error\n");
                return 0;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += mark[i];
    float avg = (float)sum / (float)n;
    printf("avg: %.1f\n", avg);
    if (avg >= mpass)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
