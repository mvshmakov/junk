// Расчет формулы.cpp: главный файл проекта.

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int m, i, k, f = 1, n = 5;
	float s = 0;
	cout << "Vvedite kol-vo prohodov: ";
	cin >> m;
	for (k = 0; k < m; k++)
	{
		cout << "No of k = " << k << endl;
		if (k == 0 || k == 1) f = 1;
		else for (i = 1; i < k + 1; i++) f *= i;
		cout << "Factorial =  " << f << endl;
		s = (pow(-1, k)) * ((pow(1, k)) / (f * (k - n)));
		cout << "Summa = " << s << endl;
		f = 1; i = 1;
		getch();
	}
	return 0;
}
