// TinkoffTask3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

int isPrime(unsigned long number);
int isEven(unsigned long number);

int main() {
	int Q, K, C;
	int counter = 0;

	std::cin >> Q;
	for (int i = 0; i < Q; i++) {
		std::cin >> K;
		std::cin >> C;
	}

	for (int i = 10000; i > 0; i--) {
		if (isPrime(i)) {
			counter++;
		};
		if (counter > Q) {
			std::cout << counter;
		}
		else {
			std::cout << "-1"
		}
	};

	return 0;
}

int isPrime(unsigned long number) { // Оптимизированный алгоритм проверки на простое число
	unsigned long i, j;
	double root = sqrt((double)number);
	i = 7; j = 11;

	if (number == 2 || number == 3 || number == 5) return 1;
	if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0) return 0;	

	while (j <= root && number % i && number % j) { i += 6; j += 6; }
	if (j <= root || i <= root && number % i == 0) return 0;

	return 1;
}

int isEven(unsigned long number) {
	if (number % 2) return 1;
	return 0;
}