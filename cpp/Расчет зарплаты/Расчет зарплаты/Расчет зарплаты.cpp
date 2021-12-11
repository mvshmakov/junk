// Расчет зарплаты.cpp: главный файл проекта.

#include "stdafx.h"
#include "conio.h"
#include "stdio.h"

using namespace System;

int main()
{
	int raz;
	float tar1 = 1000.50, tar2 = 1500, tar3 = 2300.25, tar4 = 3000, tar5 = 4000, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, ours;
	printf("Vvedite sleduyshie dannie o rabotnike:\n\n");
	printf("Razryad ot 1 do 5 vkluchitel`no: "); scanf("%i", &raz); printf("\n");
	printf("Kol-vo otrabotannih chasov: "); scanf("%f", &ours); printf("\n");
	switch (raz)
	{
	case 1: {sum1 = tar1*ours; printf("Itogovaya summa: %7.2f\n\nTablica:\n\n", sum1); } break;
	case 2: {sum2 = tar2*ours; printf("Itogovaya summa: %7.2f\n\nTablica:\n\n", sum2); } break;
	case 3: {sum3 = tar3*ours; printf("Itogovaya summa: %7.2f\n\nTablica:\n\n", sum3); } break;
	case 4: {sum4 = tar4*ours; printf("Itogovaya summa: %7.2f\n\nTablica:\n\n", sum4); } break;
	case 5: {sum5 = tar5*ours; printf("Itogovaya summa: %7.2f\n\nTablica:\n\n", sum5); } break;
	default: printf("Vvedeno nevernoe znachenie\n\nTablica:\n\n"); break;
	}
	printf("%15s%13s%13s%13s%13s%13s\n", "", "5 Razryad", "4 Razryad", "3 Razryad", "2 Razryad", "1 Razryad");
	printf("%15s%13.2f%13.2f%13.2f%13.2f%13.2f\n", "Tarif", tar5, tar4, tar3, tar2, tar1);
	printf("%15s%13.2f%13.2f%13.2f%13.2f%13.2f\n", "Kol-vo chasov", ours, ours, ours, ours, ours);
	printf("%15s%13.2f%13.2f%13.2f%13.2f%13.2f", "Summa", sum5, sum4, sum3, sum2, sum1);
	getch();
	return 0;
}
