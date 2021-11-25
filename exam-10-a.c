#include <stdlib.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS


int main()
{
	#define sportsmans 10
	#define sports 5
	#define mark_min 1
	#define mark_max 10
	int rates[sportsmans][sports];

	//ЧТЕНИЕ ИЗ ФАЙЛА

	FILE* theReadFile = fopen("exam-10.txt", "r");

	if (theReadFile == NULL) //если файла нет - записать со случайными значениями (нужен перезапуск программы)
	{
		FILE* theWriteFile = freopen("exam-10.txt", "w", stdout);
		for (int i = 0; i < sportsmans; i++)
			for (int j = 0; j < sports; j++)
			{
				printf("%d\n", 1 + (rand() % (10 - 1 + 1)));
			}
		fclose(theWriteFile);
		return 0;
	}

	for (int i = 0; i < sportsmans; i++)
		for (int j = 0; j < sports; j++)
		{
			fscanf(theReadFile, "%d", &rates[i][j]);
		}

	printf("num");

	for (int i = 0; i < sports; i++)
	{
		printf("\t%d", i + 1);
	}

	printf("\tavg");
	printf("\n\n");

	double mark_sum = 0;
	double a = sports;

	for (int i = 0; i < sportsmans; i++)
	{
		printf("%d", i + 1);
		for (int j = 0; j < sports; j++)
		{
			if (j == 0)	mark_sum = 0;
			printf("\t%d", rates[i][j]);
			mark_sum += rates[i][j];
		}

		printf("\t%.2f", mark_sum / a);
		printf("\n");
	}

	return 0;
}
