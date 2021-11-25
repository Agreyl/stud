#include <stdlib.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
#define days 31

int main()
{

	struct day_value 
	{
		int day;
		float value;

	} value[days];

	float rates_min = 10.0f;
	float rates_max = 50.0f;

	for (int i = 0; i < days; i++)
	{
		value[i].value = rates_min + ((rates_max - rates_min) * rand() / RAND_MAX);
		value[i].day = i - 1;
	}

	printf("|\tday\t|\t$\t|\n");
	for (int i = 0; i < days; i++)
	{
		printf("|\t%d\t|\t%.2f\t|\n", value[i].day, value[i].value);
	}

	float valueMin = rates_max;
	float valueMax = rates_min;
	for (int i = 0; i < days; i++)
	{
		if (value[i].value < valueMin) valueMin = value[i].value;
		if (value[i].value > valueMax) valueMax = value[i].value;
	}

	printf("min = %.2f\n", valueMin);
	printf("max = %.2f\n", valueMax);

	return 0;
}
