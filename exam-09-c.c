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

	float  rates_min = 10.0f;
	float rates_max = 50.0f;
	float x_value = -1.0f;

	//чтение файла
	FILE* theReadFile = fopen("exam-09-b.txt", "r");

	if (theReadFile == NULL) //если файла нет - записать со случайными значениями
	{
		FILE* theWriteFile = freopen("exam-09-b.txt", "w", stdout);
		for (int i = 0; i < days; i++)
			printf("%f\n", (rates_min + ((rates_max - rates_min) * rand() / RAND_MAX)));
		fclose(theWriteFile);
		return 0;
	}

	int j = 0;
	while (j < days)
	{
		fscanf(theReadFile, "%f", &value[j].value);
		value[j].day = j + 1;
		j++;
	}

	fclose(theReadFile);

	printf("|\tday\t|\t$\t|\n");
	for (int i = 0; i < days; i++)
	{
		printf("|\t%d\t|\t%.2f\t|\n", value[i].day, value[i].value);
	}

	//Поиск значения
	printf("from %.0f to %.0f\n", rates_min, rates_max);
	printf("Find value (+/- 0.5): ");

	scanf("%f", &x_value);

	if (x_value > rates_max)
		printf("It's too hight\n");
	if (x_value < rates_min)
		printf("It's too low\n");

	float valueMin = rates_max;
	float valueMax = rates_min;
	printf("Finding:\n");
	for (int i = 0; i < days; i++)
	{
		//Поиск значения 2
		
		if (value[i].value >= x_value - 0.5 && value[i].value <= x_value + 0.5 )
		{			
			printf("value: %.2f\t day: %d\n", value[i].value, value[i].day);
		}
	}

	for (int i = 0; i < days; i++)
	{
		if (value[i].value < valueMin) valueMin = value[i].value;
		if (value[i].value > valueMax) valueMax = value[i].value;
	}

	printf("min = %.2f\n", valueMin);
	printf("max = %.2f\n", valueMax);

	return 0;
}
