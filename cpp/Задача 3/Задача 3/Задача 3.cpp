// Задача 3.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>

using namespace System;
using namespace std;


int size(int* arrAfter)
{
	int a = 0;
	if (arrAfter[a] != NULL) while (arrAfter[a] != NULL) { a++; }
	return a;
};

int* func(int* arr, int N)
{
	int number = 1;
	int numberMax = 1;
	int* arrAfter = new int[N];
	arrAfter = NULL;
	for (int i = 0, j = 0; i < N - 1; i++)
	{
		if ((arr[i] % 2) && (arr[i + 1] % 2)) number++;
		else number = 1;
		if (number > numberMax) { numberMax = number; }
		if (numberMax > size(arrAfter)) { arrAfter[j] = arr[i]; j++; }
	}

	for (int k = 0; k < numberMax; k++)
	{
		cout << arrAfter[k] << " ";
	}

	return arrAfter;
};

int* createArray(int N)
{
	cout << "Vvedite massiv: ";
	int *arr = new int[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	return arr;
};

void outputArray(int* arr, int N)
{
	cout << "Vvedennii massiv: ";
	for (int i = 0; i < N; i++) cout << arr[i] << " ";
	cout << endl;
};

int main()
{
	int N;
	int *arr;
	cout << "Vvedite razmer massiva: ";
	cin >> N;

	arr = createArray(N);

	outputArray(arr, N);

	int *arr2 = func(arr, N);

	delete[] arr;
	delete[] arr2;
}