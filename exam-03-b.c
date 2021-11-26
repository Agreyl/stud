#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <ctype.h>

int main()
{
	float x0, y0;
	float s0; //нач. скорость
	float a; //угол
	double pi = 3.14159265358979323846;
	printf("x0: ");

	scanf("%f", &x0);
	printf("y0: ");
	scanf("%f", &y0);
	printf("s0: ");
	scanf("%f", &s0);
	printf("a: ");
	scanf("%f", &a);

	float rad = a * (float)pi / 180.0f; //угол в радианах

	float s0x = cosf(rad) * s0;
	float s0y = sinf(rad) * s0;

	float g = 9.8f;

	float d = s0y * s0y + 4 * g / 2.0f * y0; //дискриминант
	printf("d = %f\n", d);

	float x1 = (-s0y - sqrt(d)) / (2.0f * (-g / 2.0f));
	float x2 = (-s0y + sqrt(d)) / (2.0f * (-g / 2.0f));
	printf("x1 = %f\tx2 = %f\n", x1, x2);

	float t = 0.0f;
	float x, y;
	float epsilon = 0.01f;
	printf("epsilon = %f\n", epsilon);
	
	printf("|\tt\t|\tx\t|\ty\t|\n");
	while (1)
	{
		x = x0 + s0x * t;
		y = y0 + s0y * t - g * t * t / 2.0f;
		printf("|%f\t|%f\t|%f\t|\n", t, x, y);
		if (y <= 0.0f) break;
		t += epsilon;
	}
	

	return 0;
}
