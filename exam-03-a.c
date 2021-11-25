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

	float t1 = (-s0y - sqrt(d)) / (2.0f * (-g / 2.0f));
	float t2 = (-s0y + sqrt(d)) / (2.0f * (-g / 2.0f));
	printf("t1 = %f\tt2 = %f\n", t1, t2);

	float t = 0.0f;
	float x, y;
	float epsilon = 0.000001f;
	printf("epsilon = %f\n", epsilon);
  
	while (1)
	{
		x = x0 + s0x * t;
		y = y0 + s0y * t - g * t * t / 2.0f;
		if (y <= 0.0f) break;
		t += epsilon;
	}
	printf("t = %f\tx = %f\ty = %f\t\n", t, x, y);

	return 0;
}
