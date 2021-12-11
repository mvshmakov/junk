// ConsoleApplication2.cpp: главный файл проекта.

#include <iostream> 
#include <cmath> 

using namespace System;
using namespace std;

const double TwoPi = 6.283185307179586;
const double Pi = 3.14159265359;

float f(float x);
void outputArray(float* ptrarray, int N);
float rectangleMethod(float* ptrarray, int N, float h);
float trapeciaMethod(float* ptrarray, int N, float h);
float parabolaMethod(float* ptrarray, int N, float h);

void main()
{
	int N;
	float a, b, h;

	cout << "Vvedite N:\n";
	cin >> N;
	/*cout << "Vvedite a:\n";
	cin >> a;
	cout << "Vvedite b:\n";
	cin >> b;*/

	a = Pi; b = 2*Pi;

	float *ptrarray = new float[N];

	h = (b - a) / (N - 1);

	float x = a;
	for (int count = 0; x <= b + 1; x += h, count++)
		ptrarray[count] = f(x);

	cout << "Diskretnie znachenia funkcii: ";
	outputArray(ptrarray, N);

	cout << "\nintegral: ";
	cout << rectangleMethod(ptrarray, N, h);

	cout << "\nintegral2: ";
	cout << trapeciaMethod(ptrarray, N, h);

	cout << "\nintegral3: ";
	cout << parabolaMethod(ptrarray, N, h);

	delete[] ptrarray;
};

void outputArray(float* ptrarray, int N)
{
	for (int count = 0; count < N; count++)
		cout << ptrarray[count] << " ";
	cout << "\n";
};

float f(float x)
{
	return sin(x);
};

float rectangleMethod(float* ptrarray, int N, float h)
{
	float sum(0);
	for (int i = 0; i < N - 1; i++)
	{
		sum += ptrarray[i] * h;
	}
	return sum;
};

float trapeciaMethod(float* ptrarray, int N, float h)
{
	float sum(0);
	for (int i = 0; i < N - 1; i++)
	{
		sum += (ptrarray[i] + ptrarray[i+1]) / 2 * h;
	}
	return sum;
};

float parabolaMethod(float* ptrarray, int N, float h)
{
	float sum(0);
	for (int i = 0; i < N - 1; i++)
	{
		sum += (ptrarray[i] + ptrarray[i + 1]) / 2 * h;
	}
	return sum;
};
