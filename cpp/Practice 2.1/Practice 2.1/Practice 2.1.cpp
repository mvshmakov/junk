// Practice 2.1.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>

using namespace System;
using namespace std;

int** makeArray(int N)
{
	int **arr = new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];
	return arr;
};

void deleteArray(int** arr, int N)
{
	for (int i = 0; i < N; i++)
		delete[] arr[i];
};

void outputArray(int** arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	};
};

int** func(int** arr, int N)
{
	for (int i = 0; i < N; i++)
		for (int j = N - 1, k = i + 1; j > k; j--, k++)
		{
			int t = arr[i][j];
			arr[i][j] = arr[i][k];
			arr[i][k] = t;
		}
	return arr;
}

int main()
{
	int N;
	int** arr;
	int** arr2;
	cout << "N: ";
	cin >> N;
	arr = makeArray(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	cout << endl;

	outputArray(arr, N);

	arr2 = func(arr, N);

	cout << endl;

	outputArray(arr2, N);

	deleteArray(arr, N);
};