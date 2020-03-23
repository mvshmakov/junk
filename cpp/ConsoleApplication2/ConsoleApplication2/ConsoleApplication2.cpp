// ConsoleApplication2.cpp: главный файл проекта.

#include "stdafx.h" 
#include <iostream> 
#include <conio.h> 

using namespace std;

void input(int a[][4], int N);
void output(int a[][4], int N, int* b1, int* b2);
void func(int a[][4], int N, int* b1, int* b2);

void main()
{
	const int N = 4;
	int a[N][4];
	int b1 = 1, b2 = 1;
	input(a, N);
//	func(a, N, &b1, &b2);
	output(a, N, &b1, &b2);
	getch();
}



void input(int a[][4], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) cin >> a[i][j];
	}
	cout << endl;
}


void func(int a[][4], int N, int* b1, int* b2)
{
	for (int j = 0; j < N; j++)
	{
		for (int i = j; i < j + 1; i++) *b1 *= a[i][j];
	}
	for (int j = 0; j < N; j++)
	{
		for (int i = N - j - 1; i < N - j; i++) *b2 *= a[i][j];
	}
}


void output(int a[][4], int N, int* b1, int* b2)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	func(a, N, b1, b2);
	cout << endl << *b1 << ' ' << *b2;
}