// ConsoleApplication7.cpp: главный файл проекта.

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <conio.h>

using namespace std;

int input(int a[], int m);
void output(int a[], int k);
int sumOfElements(int a[], int k);

int main()
{
	int a[100], b[100], n = 0, k = 0;
	cout << "Vvedite 1 massiv: ";
	n = input(a, 100);
	cout << "\n1 massiv: ";
	output(a, n);
	cout << "\nVvedite 2 massiv: ";
	k = input(b, 100);
	cout << "\n\n2 massiv: ";
	output(b, k);
	cout << "\nSum of elements 1: ";
	cout << sumOfElements(a, n);
	cout << "\n\nSum of elements 2: ";
	cout << sumOfElements(b, k) << endl;
	getch();
}

int input(int a[], int m)
{
	int p = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		p++;
		if (a[i] < 0) break;
	}
	return p;
}

void output(int a[], int p)
{
	for (int i = 0; i < p - 1; i++)
		cout << a[i] << " ";
}

int sumOfElements(int a[], int k)
{
	int sum = 0;
	for (int i = 0; i < k; i++)
		if (a[i] % 2 != 0) sum += a[i];
	return sum;
}
