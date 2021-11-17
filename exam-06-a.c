#include <stdlib.h>
#include <stdio.h>
#define d 30
#define min 740
#define norm 760
#define max 780 
int main()
{
    int pressure[d];
    for (int i = 0; i < d; i++)
    {
        pressure[i] = min + (rand()%(max-min+1));
    }
    for (int i = 0; i < d; i++)
    {
        printf("%d\t%d\n", i+1, pressure[i]);
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

    return 0;
}
