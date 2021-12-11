// Массивы.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float a[10];
	float proiz = 1.0;
	int i, n, k = 0;
	cout << "Vvedite elementi massiva cherez enter:" << endl;
	for (i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\nVvedite chislo N:" << endl;
	cin >> n;
	for (i = 0; i < 10; i++)
	{
		if (a[i] > n) { k++; proiz *= a[i]; };
	}
	cout << "Proizvedenie elementov massiva = " << proiz << endl;
	cout << "Kol-vo elementov bolshih chisla = " << k << endl;
	getch();
    return 0;
}
