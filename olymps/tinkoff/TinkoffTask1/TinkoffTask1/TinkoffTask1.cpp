// TinkoffTask1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

void main() {
	int L, R; // Инициализация переменных
	int result = 0; // Счетчик для общего количества действий

	std::cin >> L; // Ввод L
	std::cin >> R; // Ввод R

	for (int i = L; i < (R + 1); i++) { //Для каждого элемента из диапазона L..R
		int counter = 0, current = i;

		while (current != 1) { // Реализация гипотезы Коллатца 

			if (current % 2 == 0) { current = current / 2; }
			else { current = 3 * current + 1; };

			counter++;
		};

		result += counter; 
	};

	std::cout << result; // Вывод результата
}