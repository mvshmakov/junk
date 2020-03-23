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

void func(int** arr, int N)
{
		int K = 2;
		while (K<N)
		{
			int label = 0;
			for (int i = 0; i <= N - K; i++)
				for (int j = 0; j <= N - K; j++)
				{
					for (int x = i; x<i + K; x++)
						for (int y = j; y<j + K; y++)
						{
							if (arr[x][y] % 2 == 0)
								label++;
						}
					if (label == (K*K) && (j + K - 1 + i == N - 1))
					{
						cout << endl;
						for (int x = i; x<i + K; x++)
						{
							for (int y = j; y<j + K; y++)
								cout << arr[x][y] << " ";
							cout << endl;
						}
					}
					label = 0;
				}
			K++;
		}
		cout << endl;
};

int main()
{
	int N;
	int** arr;

	cout << "N: ";
	cin >> N;

	arr = makeArray(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	cout << endl;

	outputArray(arr, N);

	cout << endl;

	func(arr, N);

	deleteArray(arr, N);
};