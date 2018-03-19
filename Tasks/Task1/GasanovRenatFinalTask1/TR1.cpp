#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string rus[74] = { "А", "а", "Б", "б",    "В", "в", "Г", "г", "Ґ", "ґ", "Д", "д", "Е", "е", "Є", "є", "Ж", "ж", "З", "з", "И", "и", "І", "і", "Ї", "ї", "Й", "й", "К", "к",
		"Л", "л", "М", "м", "Н", "н", "О", "о", "П", "п",   "Р", "р", "С", "с", "Т", "т", "У", "у", "Ф", "ф",   "Х", "х", "Ц", "ц", "Ч", "ч",   "Ш", "ш",
		"Щ", "щ", "Ь", "ь", "Ю", "ю",   "Я", "я", "Ы", "ы", "Ъ", "ъ", "Ё", "ё", "Э", "э" };

	string eng[74] = { "A", "a", "B", "b",    "V", "v", "G", "g", "G", "g", "D", "d", "E", "e", "E", "E", "Zh", "zh", "Z", "z", "I", "i", "I", "I", "Yi", "yi", "J", "j", "K", "k",
		"L", "l", "M", "m", "N", "n", "O", "o", "P", "p",   "R", "r", "S", "s", "T", "t", "U", "u", "F", "f",   "H", "h", "Ts", "ts", "Сh", "ch", "Sh", "sh",
		"Shh", "shh", "'", "'", "Yu", "yu","Ya", "ya", "Y", "y", "", "", "Yo", "yo", "E", "e" };

	string text("Текст бывает разный"); 
	bool find = false;
	string output;
	for (int i = 0; i <= text.length(); i++)
	{
		find = false;
		for (int j = 0; j<74; j++)
		{
			if (text.substr(i, 1).compare(rus[j]) == 0) { output += eng[j]; find = true;  break; }
		}
		if (!find) output += text.substr(i, 1);
	}
	cout << output << endl;
	system("pause");
	return 0;
}