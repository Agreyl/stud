#include <stdlib.h>
#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
#define months 12
int main()
{

	int salary[months];
	int salary_min = 1000;
	int salary_max = 5000;
	float tax[months];


	//Ежемесячные отчисления (подсчеты)
	for (int i = 0; i < months; i++)
	{
		salary[i] = salary_min + rand() % (salary_max - salary_min + 1);
		tax[i] = (float)(salary[i] * 0.02f); //2% налог
	}

	//Суммарная зп за год (подсчеты)
	int salary_year = 0;
	for (int i = 0; i < months; i++)
		salary_year += salary[i];
	
	//Средняя зп за год (подсчеты)
	float salary_year_avg = salary_year / (float)months;


	printf("|month\t\t|salary\t\t|deviation\t|tax\t\t|\n");
	for (int i = 0; i < months; i++)
	{
		printf("|\t%d\t|", (i + 1)); //месяц
		printf("\t%d\t|", salary[i]); //ЗП
		printf("\t%.1f%\t|", ((float)salary[i] / salary_year_avg) * 100.0f); //Отклонение
		printf("\t%.1f\t|\n", tax[i]); //Налог
	}



	//Суммарный налог за год
	float tax_year = 0;
	for (int i = 0; i < months; i++)
		tax_year += tax[i];
	printf("Year tax = %.2f\n", tax_year);

	
	printf("Year salary = %d\n", salary_year);


	printf("Average salary = %.2f\n", salary_year_avg);

	struct month_salary
	{
		int month;
		int salary;
	} month_salary[months];

	for (int i = 0; i < months; i++)
	{
		month_salary[i].month = i + 1;
		month_salary[i].salary = salary[i];
	}

	int tmp;
	int tmp_month;
	for (int i = 0; i < months - 1; i++)
		for (int j = 0; j < months - i - 1; j++)
		{
			if (month_salary[j].salary > month_salary[j + 1].salary)
			{
				tmp = month_salary[j].salary;
				tmp_month = month_salary[j].month;
				month_salary[j].salary = month_salary[j + 1].salary;
				month_salary[j].month = month_salary[j + 1].month;
				month_salary[j + 1].salary = tmp;
				month_salary[j + 1].month = tmp_month;
			}
		}

	printf("Min salary = %d\tMonth:%d\n", month_salary[0].salary ,month_salary[0].month);
	printf("Max salary = %d\tMonth:%d\n", month_salary[months - 1].salary, month_salary[months - 1].month);


	return 0;
}
