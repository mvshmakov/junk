// Practice1.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>

using namespace System;
using namespace std;

void func(int* arr, int N)
{
	for (int j = N; j > 0; j--)
		for (int i = 0; i < j; i++)
			if (((arr[i] - arr[j]) < 4) && ((arr[j] - arr[i]) < 4)) cout << i + 1 << " " << j + 1 << endl;
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

	func(arr, N);

	delete[] arr;
}