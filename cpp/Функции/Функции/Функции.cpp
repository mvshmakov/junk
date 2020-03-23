// Функции.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int input(int a[], int m);
void output(int a[], int k);
int noOfElement(int a[], int k, float t);

void main()
{
	int a[100], b[100], n, k;
	float t;
	cout << "Vvedite 1 massiv: ";
	n = input(a, 100);
	//cout << "\nVvedite 2 massiv: ";
	//k = input(b, 100);
	//cout << "\n1 massiv: ";
	//output(a, n);
	//cout << "\n\n2 massiv: ";
	//output(b, k);
	cout << "\n\nVvedite chislo: ";
	cin >> t;
	cout << "\nNo of the position: " << noOfElement(a, n, t);
	//cout << "\n\nNo of the position: " << noOfElement(b, k, t);
	getch();
}

int input(int a[], int m)
{
	int i, k=0;
	for (int i = 0; i < m; i++)
	{ 
		cin >> a[i];
		if (a[i] < 0) break;
		k++;
	}
	output(a, k);
	return k;
}

void output(int a[], int k)
{
	for (int i = 0; i < k; i++) cout << a[i] << " ";
}

int noOfElement(int a[], int k, float t)
{
	int m = 0;
	for (int i = 0; i < k; i++)
		if (a[i] > t) { return i; break; } else m++;
	if (m == k) return -1;
}