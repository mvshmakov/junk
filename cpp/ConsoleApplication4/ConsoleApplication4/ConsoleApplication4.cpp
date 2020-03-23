// ConsoleApplication4.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;
struct complex { float Re, Im; };
complex input(complex A);
void output(complex A);
complex subtraction(complex A, complex B);

void main()
{
	complex A = { 0, 0 }, B{ 0, 0 }, C;
	A = input(A);
	B = input(B);

	C = subtraction(A, B);


	output(C);




	getch();
}





void output(complex A)
{
	cout << "(" << A.Re << ", " << A.Im << ")" << endl;
}
complex input(complex A)
{
	cin >> A.Re >> A.Im;
	return A;
}
complex subtraction(complex A, complex B)
{
	complex C;
	C.Re = (B.Re - A.Re);
	C.Im = (B.Im - A.Im);
	return C;
}