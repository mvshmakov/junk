// ConsoleApplication9.cpp: ������� ���� �������.

#include <stdio.h>
#include <iostream>
#include <climits>
#include <math.h>


using namespace std;

int main()
{
	for (unsigned long long int k = 0, i; k < 6; k++)
	{
		i = pow(2.0, pow(2.0, (double)k)) + 1;
		cout << i << " ";
	}
	getchar();
}
