#include <stdlib.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS


int main()
{
	#define subjects 5
	#define students 25
	#define mark_min 2
	#define mark_max 5
	int marks[subjects][students];

	//ЧТЕНИЕ ИЗ ФАЙЛА

	FILE* theReadFile = fopen("exam-11.txt", "r");

	if (theReadFile == NULL) //если файла нет - записать со случайными значениями
	{
		FILE* theWriteFile = freopen("exam-11.txt", "w", stdout);
		for (int i = 0; i < subjects; i++)
			for (int j = 0; j < students; j++)
			{
				printf("%d\n", mark_min + (rand() % (mark_max - mark_min + 1)));
			}
		fclose(theWriteFile);
		return 0;
	}

	for (int i = 0; i < subjects; i++)
		for (int j = 0; j < students; j++)
		{
			fscanf(theReadFile, "%d", &marks[i][j]);
		}

	printf("num");

	for (int i = 0; i < students; i++)
	{
		printf("\t%d", i + 1);
	}

	printf("\tavg");
	printf("\n\n");

	double mark_sum = 0;
	double a = students;
	
	struct SM_avgmark
	{
		int subject;
		double avg_mark;
	}subj_avgmark[subjects];

	for (int i = 0; i < subjects; i++)
	{
		printf("%d", i + 1);
		for (int j = 0; j < students; j++)
		{
			if (j == 0)	mark_sum = 0;

			printf("\t");
			printf("%d", marks[i][j]);
			mark_sum += marks[i][j];

		}
		subj_avgmark[i].subject = i + 1;
		subj_avgmark[i].avg_mark = mark_sum / a;
		printf("\t%.2f", subj_avgmark[i].avg_mark);
		printf("\n");
	}
	int worse_subj = 1;
	for (int i = 0; i < subjects; i++)
	{
		if (subj_avgmark[i].avg_mark <= subj_avgmark[worse_subj - 1].avg_mark) worse_subj = subj_avgmark[i].subject;
		
	}
//	printf("Worse subject: %d", worse_subj);

	return 0;
}
