// ConsoleApplication12.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	while (1) {
		double f, w, answer, cosin;
		cin >> f;
		w = 2 * 3.1415 * f;
		answer = atan(((w * 0.001) - (1 / w * 0.0000001)) / 60) * 180 / 3.1415;
		cosin = cos(answer / 180 * 3.1415);
		cout << w << endl;
		cout << answer << endl;
		cout << cosin << endl;
	}
}