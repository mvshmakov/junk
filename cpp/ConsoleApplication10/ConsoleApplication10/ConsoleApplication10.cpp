// ConsoleApplication10.cpp: главный файл проекта.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <climits>
#include "conio.h"


using namespace std;

int main()
{
	int k(0);
	double y1(0), y2(0), eps;
	cout << "Vvedite eps: ";
	cin >> eps;
	do {
		y1 = y2;
		y2 = (y1 + 1) / (y1 + 2);
		k++;
	} while ((y2 - y1) > eps);
	cout << "k: " << k << endl;
	cout << "Number: " << y2;
	getch();
}