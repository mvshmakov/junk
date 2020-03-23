// TinkoffTask2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main() {
	int N1, Vx1, Vy1, N2, Vx2, Vy2;

	std::cin >> N1;
	std::cin >> Vx1;
	std::cin >> Vy1;
	int** vertices1 = new int*[N1];
	for (int i = 0; i < N1; i++) {
		vertices1[i] = new int[1];
	};
	for (int i = 0; i < N1; i++) {
		std::cin >> vertices1[i][0];
		std::cin >> vertices1[i][1];
	};

	std::cin >> N2;
	std::cin >> Vx2;
	std::cin >> Vy2;
	int** vertices2 = new int*[N2];
	for (int i = 0; i < N2; i++) {
		vertices2[i] = new int[1];
	};
	for (int i = 0; i < N2; i++) {
		std::cin >> vertices2[i][0];
		std::cin >> vertices2[i][1];
	};
	
	if (Vx2 == 0 || Vy2 == 0) {
		if ((Vx1 == Vx2) || (-Vx1 == Vx2)) {
			goto mainCode;
		};
	} 
	else if ((Vx1 / Vx2) == (Vy1 / Vy2)) { // Проверка на коллинеарность векторов скорости
	mainCode:

		int maxVx1 = vertices1[0][0], minVx2 = vertices2[0][0], maxVy1 = vertices1[0][1], minVy2 = vertices2[0][1];
		int minVx1 = vertices1[0][0], maxVx2 = vertices2[0][0], minVy1 = vertices1[0][1], maxVy2 = vertices2[0][1];
		
		for (int i = 0; i < N1; i++) {
			if (maxVx1 < vertices1[i][0]) { maxVx1 = vertices1[i][0]; }
			if (maxVy1 < vertices1[i][1]) { maxVy1 = vertices1[i][1]; }
			if (minVx1 > vertices1[i][0]) { minVx1 = vertices1[i][0]; }
			if (minVy1 > vertices1[i][1]) { minVy1 = vertices1[i][1]; }
		};
		for (int i = 0; i < N2; i++) {
			if (minVx2 > vertices2[i][0]) { minVx2 = vertices2[i][0]; }
			if (minVy2 > vertices2[i][1]) { minVy2 = vertices2[i][1]; }
			if (maxVx2 < vertices2[i][0]) { maxVx2 = vertices2[i][0]; }
			if (maxVy2 < vertices2[i][1]) { maxVy2 = vertices2[i][1]; }
		};

		if (!(((minVx2 > maxVx1) || (maxVx2 < minVx1)) && ((maxVy2 < minVy1) || (minVy2 > maxVy1)))) {
			std::cout << "Yes";
		}
		else {
			std::cout << "No";
		};
	}
	else { std::cout << "No"; }
	
	delete[] vertices1;
	delete[] vertices2;

    return 0;
}
