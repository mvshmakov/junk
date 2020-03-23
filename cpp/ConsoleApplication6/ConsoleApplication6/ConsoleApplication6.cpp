

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;
using namespace System;

void input(int A[][4], int, int);
void output(int A[][4], int, int);
void output1(float B[], int);
void sozd(int A[][4], float B[], int, int);
void sort(int A[][4], int, int);

void main()

{
	int A[3][4];
	float B[4];
	input(A, 3, 4);
	output(A, 3, 4);
	cout << endl;
	sozd(A, B, 3, 4);

	output1(B, 4);
	sort(A, 3, 4);
	cout << endl;
	output(A, 3, 4);
	cout << endl;
	getch();

}
void input(int A[][4], int n, int m)
{
	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			cin >> A[i][j];
}

void output(int A[][4], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;


		for (int j = 0; j < m; j++)
		{
			cout.width(3);
			cout << A[i][j] << " ";
		}
	}
}



void sozd(int A[][4], float B[], int n, int m)
{
	for (int j = 0; j < m; j++)
	{
		int k = 0;
		float sum = 0, sr_ar = 0;
		
		for (int i = 0; i < n; i++)
		{
			
			 if (A[i][j] < 0)
			{
				sum += A[i][j]; k++;
			}
			 else sum = 0;
			

			sr_ar = sum / k;
			B[j] = sr_ar;
		}

	}
}

void sort(int A[][4], int n, int m)
{
	int d;
	for (int k = 0; k < n; k++)

		for (int i = 0; i < n; i++)

			for (int j = 0; j < m - 1; j++)

				if (A[i][j] > A[i][j + 1])

				{
					d = A[i][j + 1];
					A[i][j + 1] = A[i][j];
					A[i][j] = d;
				}

}


void output1(float B[], int m)
{
	for (int j = 0; j < m; j++)
	{
		cout.width(3);
		cout << B[j] << " ";
	}

}




