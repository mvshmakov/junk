// ConsoleApplication3.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

struct dot
{
	float x, y;
};

struct otrezok
{
	dot o1, o2;
};

dot inputdot();
void outputdot(dot x);
otrezok inputotr();
void outputotr(otrezok xy);
int func(dot x, otrezok xy);


void main()
{
	dot x;
	otrezok xy;
	cout << "Vvedite koordinati tochki: ";
	x = inputdot();
	cout << "Vvedite koordinati otrezka: ";
	xy = inputotr();
	cout << "Koordinati tochki: ";
	outputdot(x);
	cout << "Koordinati otrezka: ";
	outputotr(xy);
	if (func(x, xy)) {cout << "Ne prinadlezhit";}
	else cout << "Prinadlezhit";
	getch();
}

dot inputdot()
{
	dot x;
	cin >> x.x >> x.y;
	return x;
}


otrezok inputotr()
{
	otrezok xy;
	cout << endl << "Pervaya tochka: ";
	cin >> xy.o1.x >> xy.o1.y;
	cout << "Vtoraya tochka: ";
	cin >> xy.o2.x >> xy.o2.y;
	return xy;
}


void outputdot(dot x)
{
	cout  << "(" << x.x << ";" << x.y << ")"<< endl;
}


void outputotr(otrezok xy)
{
	cout  << "(" << xy.o1.x << ";" << xy.o1.y << ")" << " " << "(" << xy.o2.x << ";" << xy.o2.y << ")" << endl;
}

int func(dot x, otrezok xy)
{
	float coord1;
	coord1 = xy.o2.x - xy.o1.x;
	if ((x.x >= 0) && (x.x <= coord1)) { return 1; }
	else return 0;
}