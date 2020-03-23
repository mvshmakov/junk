#include "stdafx.h" 
#include <iostream> 
#include <math.h> 

using namespace System;
using namespace std;


float fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);

}


int main()
{
	float s = 0.3, E = 0.5, F = 0, D, sum = 0;
	float factorial = 1;
	float n = 1;

	do 
	{
		sum += F;
		D = F;
		factorial = fact(n);
		float q = pow(2, n) * pow(s, n);
		F = q / factorial;

		n++;
	} while ((F - D)>E);

	cout << sum;

	return 0;
}