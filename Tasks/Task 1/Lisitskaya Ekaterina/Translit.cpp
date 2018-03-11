//#include <iostream>
#include <cstring>
#include "translit_lib.h"
#include "stdio.h"
#include "stdlib.h"
//#include "stdafx.h"

using namespace std;

char lat[66][8] = { "A", "B", "V", "G", "D", "Ye", "Yo", "Zh",
"Z", "I", "Ii", "K", "L", "M", "N", "O",
"P", "R", "S", "T", "U", "F", "H", "C",
"Ch", "Sh", "Sch", "!", "Y", "?", "E", "Yu", "Ya",
"a",  "b",  "v",  "g",  "d",   "e", "yo", "zh",
"z",  "i", "ii",  "k",  "l",   "m",  "n",  "o",
"p",  "r",  "s",  "t",  "u",   "f",  "h",  "c",
"ch", "sh","sch",  "!",  "y",  "?'", "e", "yu", "ya" };

char rus[166] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";

char* cyrillicToLat(int fByte, int sByte)
{
	int i(0);
	while ((i < 164) && (((int)rus[i] != fByte) || ((int)rus[i + 1] != sByte))) i += 2;
	if (i == 164) return '\0';
	else return lat[i / 2];
}

char* TranslitLib::translit(char *message)
{
	char* result = new char[strlen(message) * 3];
	*result = { '\0' };

	char* symbol;
	for (int i = 0; i < strlen(message); i += 2)
	{
		symbol = cyrillicToLat(message[i], message[i + 1]);
		if (symbol == NULL) strcat(result, message);
		else strcat(result, symbol);
	}
	return result;
}

int main()
{
	char*  message = (char*)malloc(strlen("Узумаки") + 1);
		strcpy(message, "Узумаки");
	printf ("%s", TranslitLib::translit(message)) ;
	return 0;
}

