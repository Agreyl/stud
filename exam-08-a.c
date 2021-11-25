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


	//Ежемесячные отчисления
	printf("|\tmonth\t|\tsalary\t|\ttax\t|\n");
	for (int i = 0; i < months; i++)
	{
		salary[i] = salary_min + rand() % (salary_max - salary_min + 1);
		tax[i] = (float)(salary[i] * 0.02f); //2% налог
		printf("|\t%d\t|", (i + 1)); //месяц
		printf("\t%d\t|", salary[i]); //ЗП
		printf("\t%.1f\t|\n", tax[i]); //Налог
	}

	//Суммарный налог за год
	float tax_year = 0;
	for (int i = 0; i < months; i++)
		tax_year += tax[i];
	printf("Year tax = %.2f\n", tax_year);

	//Суммарная зп за год
	int salary_year = 0;
	for (int i = 0; i < months; i++)
		salary_year += salary[i];
	printf("Year salary = %d\n", salary_year);

	//Средняя зп за год
	float salary_year_avg = salary_year / (float)months;
	printf("Average salary = %.2f\n", salary_year_avg);


	return 0;
}
