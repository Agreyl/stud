#include <stdlib.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS


int main()
{
	#define students 25
	#define subjects 5
	#define mark_min 2
	#define mark_max 5
	int marks[students][subjects];

	//ЧТЕНИЕ ИЗ ФАЙЛА

	FILE* theReadFile = fopen("exam-11.txt", "r");

	if (theReadFile == NULL) //если файла нет - записать со случайными значениями
	{
		FILE* theWriteFile = freopen("exam-11.txt", "w", stdout);
		for (int i = 0; i < students; i++)
			for (int j = 0; j < subjects; j++)
			{
				printf("%d\n", mark_min + (rand() % (mark_max - mark_min + 1)));
			}
		fclose(theWriteFile);
		return 0;
	}

	for (int i = 0; i < students; i++)
		for (int j = 0; j < subjects; j++)
		{
			fscanf(theReadFile, "%d", &marks[i][j]);
		}

	printf("num");

	for (int i = 0; i < subjects; i++)
	{
		printf("\t%d", i + 1);
	}

	printf("\tavg");
	printf("\n\n");

	double mark_sum = 0;
	double a = subjects;
	
	struct SM_avgmark
	{
		int subject;
		double avg_mark;
	}subj_avgmark[students];

	for (int i = 0; i < students; i++)
	{
		printf("%d", i + 1);
		for (int j = 0; j < subjects; j++)
		{
			if (j == 0)	mark_sum = 0;
			printf("\t%d", marks[i][j]);
			mark_sum += marks[i][j];

		}
		subj_avgmark[i].subject = i + 1;
		subj_avgmark[i].avg_mark = mark_sum / a;
		printf("\t%.2f", subj_avgmark[i].avg_mark);
		printf("\n");
	}
	int worse_subj = 1;
	for (int i = 0; i < students; i++)
	{
		if (subj_avgmark[i].avg_mark <= subj_avgmark[worse_subj - 1].avg_mark) worse_subj = subj_avgmark[i].subject;
		

	}
	//printf("Worse subject: %d", worse_subj);
	return 0;
}
