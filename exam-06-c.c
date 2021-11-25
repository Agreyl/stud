#include <stdlib.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
#define d 30
#define min 740
#define norm 760
#define max 780 

int main()
{
    struct day_pressure
    {
        int day;
        int pressure;

    } ;
    struct day_pressure pressure[d];
    for (int i = 0; i < d; i++)
    {
        pressure[i].pressure = min + (rand() % (max - min + 1));
        pressure[i].day = i + 1;
    }
    for (int i = 0; i < d; i++)
    {
        printf("%d\t%d\n", pressure[i].day, pressure[i].pressure);
    }

    int d_below = 0;
    int d_above = 0;
    int d_exact = 0;

    for (int i = 0; i < d; i++)
    {
        int v = pressure[i].pressure;
        if (v < norm) d_below++;
        else if (v > norm) d_above++;
        else d_exact++;
    }

    printf("below: %d\n", d_below);
    printf("above: %d\n", d_above);
    printf("exact: %d\n", d_exact);

    printf("Delete day?\nY/N:");
    char YN;
    int dm;
    scanf("%s", &YN);
    if (YN == 'y' || YN == 'Y')
    {
        printf("Day of month:\n");
        scanf("%d", &dm);
        for (int i = 0; i < d; i++)
        {
            if (i == dm - 1)
            {
                pressure[i].pressure = -1;
                printf("Deleted succesfully.\n");

            }
        }
        for (int i = 0; i < d; i++)
        {
            if (pressure[i].pressure != -1)
                printf("%d\t%d\n", pressure[i].day, pressure[i].pressure);
            else printf("%d\tDELETED\n", pressure[i].day);
        }

    }

    printf("Sort days?\nY/N:");
    int s;
    scanf("%s", &YN);
    if (YN == 'y' || YN == 'Y')
    {

        for (int i = 0; i < d - 1; i++)
        {
            for (int j = d - 1; j > i; j--)
            {
                if (pressure[j - 1].pressure > pressure[j].pressure)
                {
                    int savePress = pressure[j - 1].pressure;
                    pressure[j - 1].pressure = pressure[j].pressure;
                    pressure[j].pressure = savePress;

                    int saveDate = pressure[j - 1].day;
                    pressure[j - 1].day = pressure[j].day;
                    pressure[j].day = saveDate;
                }
            }
                
        }
            
        
        
        
        
        for (int i = 0; i < d; i++)
        {
            if (pressure[i].pressure != -1)
                printf("%d\t%d\n", pressure[i].day, pressure[i].pressure);
            else printf("%d\tDELETED\n", pressure[i].day);
        }

    }



    return 0;
}
