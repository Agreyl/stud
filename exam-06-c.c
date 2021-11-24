#include <stdlib.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
#define d 30
#define min 740
#define norm 760
#define max 780 

int cmp(const void* a, const void* b) 
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int pressure[d];
    for (int i = 0; i < d; i++)
    {
        pressure[i] = min + (rand() % (max - min + 1));
    }
    for (int i = 0; i < d; i++)
    {
        printf("%d\t%d\n", i + 1, pressure[i]);
    }

    int d_below = 0;
    int d_above = 0;
    int d_exact = 0;

    for (int i = 0; i < d; i++)
    {
        int v = pressure[i];
        if (v < norm) d_below++;
        else if (v > norm) d_above++;
        else d_exact++;
    }

    printf("below: %d\n", d_below);
    printf("above: %d\n", d_above);
    printf("exact: %d\n", d_exact);

    printf("Delete day? Print '1' if yes, '0' if no.\n");
    int g;
    int dm;
    scanf("%d\n", &g);
    if (g == 1)
    {
        printf("Day of month:\n");
        scanf("%d\n", &dm);
        for (int i = 0; i < d; i++)
        {
            if (i == dm - 1)
            {
                pressure[i] = -1;
                printf("Deleted succesfully.\n");

            }            
        }
        for (int i = 0; i < d; i++)
        {
            if (pressure[i] != -1)
            printf("%d\t%d\n", i + 1, pressure[i]);
            else printf("%d\tDELETED\n", i + 1);
        }

    }

    printf("Sort days? Print '1' if yes, '0' if no.\n");
    int s;
    scanf("%d\n", &s);
    if (s == 1)
    {
        qsort(pressure, d, sizeof(int), cmp);
        for (int i = 0; i < d; i++)
        {
            if (pressure[i] != -1)
                printf("%d\t%d\n", i + 1, pressure[i]);
            else printf("%d\tDELETED\n", i + 1);
        }

    }



    return 0;
