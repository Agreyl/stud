#include <stdlib.h>
#include <stdio.h>
#define d 30
#define min 740
#define norm 760
#define max 780
int main()
{
    int pressure[d];
    for (int i = 0; i <= d; i++)
    {
        pressure[i] = min + (rand()%(max-min+1));
    }
    for (int i = 0; i <= d; i++)
    {
        printf("%d\t%d", i+1, pressure[i]);
    }
    return 0;
}