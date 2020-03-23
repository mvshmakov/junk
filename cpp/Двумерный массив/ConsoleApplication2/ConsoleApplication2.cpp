// ConsoleApplication2.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

void input(int a[][4], int N, int M);
void output2(int a[][4], int N, int M);
void KolvoEl(int a[][4], int N, int M, int b[]);
void output1(int b[], int M);
void sort(int a[][4], int N, int M);


void main()
{
	cout << "Vvedite massiv: " << endl;
	const int N = 3; 
	const int M = 4;
	int a[N][M], b[M];
	input(a, N, M);
	cout << "Vvedennii massiv: " << endl;
	output2(a, N, M);
	cout << "Kol-vo elementov, ravnih -1: ";
	KolvoEl(a, N, M, b);
	output1(b, M);
	sort(a, N, M);
	cout << "Otsortirovannii massiv: " << endl;
	output2(a, N, M);
	getch();
}
	

void input(int a[][4], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) cin >> a[i][j];
	}
}

void KolvoEl(int a[][4], int N, int M, int b[])
{
	int j = 0;
	for ( ; j < M; j++)
	{
		int t = 0;
		for (int i = 0; i < N; i++)
		{
			if (a[i][j] == -1) t++;
		}
		b[j] = t;
	}
}

void sort(int a[][4], int N, int M)
{
	int t;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = j + 1; k < M; k++)
				if (a[i][k] > a[i][j]) { t = a[i][j]; a[i][j] = a[i][k]; a[i][k] = t; };
		}
	}
}

void output2(int a[][4], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void output1(int b[], int M)
{
	for (int i = 0; i < M; i++)
		cout << b[i] << " ";
	cout << endl;
}