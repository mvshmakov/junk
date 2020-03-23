// ConsoleApplication11.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>

using namespace std;

class Dot {
public:
	Dot() { x = 0; y = 0; z = 0;}

	Dot(double dx, double dy, double dz) { x = dx; y = dy; z = dz; }

	void output() { cout << "Dot: " << "(" << x << ", " << y << ", " << z << ")" << endl; }

	double getAxis(char i) {
		switch (i)
		{
		case 'x': return x;
		case 'y': return y;
		case 'z': return z;
		}
	}

	~Dot() { cout << "Class Dot is destructed" << endl; }

private:
	double x, y, z;
};

class Vector3D {
public:
	Vector3D(double x, double y, double z) {
		new(&a) Dot(0, 0, 0);
		new(&b) Dot(x, y, z);
		//this->a = Dot::Dot(0.0, 0.0, 0.0);
		//Dot a(0, 0, 0);
		//this->b = Dot::Dot(x, y, z);
		//Dot b(x, y, z);
	}

	void output() { cout << "Vector: " << endl; a.output(); b.output(); }

	void scale(double mult) {
		new(&a) Dot(a.getAxis('x')*mult, a.getAxis('y')*mult, a.getAxis('z')*mult);
		new(&b) Dot(b.getAxis('x')*mult, b.getAxis('y')*mult, b.getAxis('z')*mult);
	}

	Dot &getDot(bool i) {
		if (!i) return a;
		else return b;
	}

	~Vector3D() { cout << "Class Vector3D is destructed" << endl; }

private:
	Dot a, b;
};

void multiply(Vector3D& vect, double x);

int main()
{
	Dot a(1.0, 0.0, 3.0);
	a.output();
	Vector3D vect(1.0, 1.0, 1.0);
	vect.output();
	vect.scale(3);
	vect.output();
	multiply(vect, 3);
	vect.output();
};

void multiply(Vector3D& vect, double x) {
	new(&vect.getDot(0)) Dot(vect.getDot(0).getAxis('x')*x, vect.getDot(0).getAxis('y')*x, vect.getDot(0).getAxis('z')*x);
	new(&vect.getDot(1)) Dot(vect.getDot(1).getAxis('x')*x, vect.getDot(1).getAxis('y')*x, vect.getDot(1).getAxis('z')*x);
};