//  вадратное уравнение.cpp: главный файл проекта.

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <math.h>

using namespace System;

int main()
{
	float x1, x2, a, b, c, d;
	printf("vvedite a, b, c\n");
	scanf("%f%f%f", &a, &b, &c);
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0) printf("diskriminant ne opredelen\nbeskonechnoe kol-vo korney");
			else printf("diskriminant ne opredelen\nnet resheniya");
		}
		else
		{
			x1 = - (c / b);
			printf("discriminant ne opredelen\nkorni: x1=x2=%5.2f", x1);
		}
	}
	else
	{
		d = b*b - 4 * a*c;
		if (d == 0)
		{
			x1 = - (b / (2 * a));
			printf("discriminant: d=%5.2f\nkorni: x1=x2=%5.2f", d, x1);
		}
		else
		{
			if (d < 0) printf("discriminant: d=%5.2f\nkompleksnie korni", d);
			else { x1 = (-b + sqrt(d)) / (2 * a); x2 = (-b - sqrt(d)) / (2 * a); printf("discriminant: d=%5.2f\nkorni: x1=%5.2f x2=%5.2f", d, x1, x2); }
		}
	}
	getch();
	return 0;
}