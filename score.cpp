#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "locale.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	int i, score = 0;
	float  a = 7, b = 5;
	printf("Укажите кол-во выстрелов \n");
	scanf_s("%d", &i);
	for (int counter = 0; counter < i; counter++) {
		float  x, y, elip;
		x = 1 + rand() % 6;
		y = 1 + rand() % 6;
		elip = ((x*x) / (a*a)) + ((y*y) / (b*b));
		printf("Координаты выстрела: %f %f \n", x, y);
		if (elip > 1) {
			printf("Это фиаско, братан! \n");
		}
		else {
			float  c = 5, d = 3;
			elip = ((x*x) / (c*c)) + ((y*y) / (d*d));
			if (elip > 1) {
				score = score + 1;
				printf("Ну хоть что-то!  Кол-во очков: %d \n ", score);
			}
			else {
				float  g = 3, h = 1;
				elip = ((x*x) / (g*g)) + ((y*y) / (h*h));
				if (elip > 1) {
					score = score + 3;
					printf("Хорошо!  Кол-во очков: %d \n ", score);
				}
				else {
					score = score + 5;
					printf("В яблочко!  Кол-во очков: %d \n ", score);
				}
			}
		}
	}
	system("pause");
	return 0;
}