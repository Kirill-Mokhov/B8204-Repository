#include "Translit.h"

void translit(char* str)
{
	

	int i(0);

while (str[i] != '\0')
{

	switch (str[i])
	{
	case 'А': cout << "А"; break;
	case 'Б': cout << "B"; break;
	case 'В': cout << "V"; break;
	case 'Г': cout << "G"; break;
	case 'Д':
	{
		if (str[i + 1] == 'ж')
		{
			cout << "J";
			i++;
		}
		else
			cout << "D";
	} break;
	case 'Е': cout << "E"; break;
	case 'Ё': cout << "Yo"; break;
	case 'Ж': cout << "Zh"; break;
	case 'З': cout << "Z"; break;
	case 'И': cout << "I"; break;
	case 'Й': cout << "Y"; break;
	case 'К': cout << "K"; break;
	case 'Л': cout << "L"; break;
	case 'М': cout << "M"; break;
	case 'Н': cout << "N"; break;
	case 'О': cout << "O"; break;
	case 'П': cout << "P"; break;
	case 'Р': cout << "R"; break;
	case 'С': cout << "S"; break;
	case 'Т': cout << "T"; break;
	case 'У': cout << "U"; break;
	case 'Ф': cout << "F"; break;
	case 'Х': cout << "H"; break;
	case 'Ц': cout << "Ts"; break;
	case 'Ч': cout << "Ch"; break;
	case 'Ш': cout << "Sh"; break;
	case 'Щ': cout << "Sch"; break;
	case 'Ъ': cout << ""; break;
	case 'Ы': cout << "Yi"; break;
	case 'Ь': cout << ""; break;
	case 'Э': cout << "E"; break;
	case 'Ю': cout << "Yu"; break;
	case 'Я': cout << "Ya"; break;

	case 'а': cout << "a"; break;
	case 'б': cout << "b"; break;
	case 'в': cout << "v"; break;
	case 'г': cout << "g"; break;
	case 'д': {
		if (str[i + 1] == 'ж')
		{
			cout << "j";
			i++;
		}
		else
			cout << "d";
	} break;
	case 'е': cout << "e"; break;
	case 'ё': cout << "yo"; break;
	case 'ж': cout << "zh"; break;
	case 'з': cout << "z"; break;
	case 'и': cout << "i"; break;
	case 'й': cout << "y"; break;
	case 'к': cout << "k"; break;
	case 'л': cout << "l"; break;
	case 'м': cout << "m"; break;
	case 'н': cout << "n"; break;
	case 'о': cout << "o"; break;
	case 'п': cout << "p"; break;
	case 'р': cout << "r"; break;
	case 'с': cout << "s"; break;
	case 'т': cout << "t"; break;
	case 'у': cout << "u"; break;
	case 'ф': cout << "f"; break;
	case 'х': cout << "h"; break;
	case 'ц': cout << "ts"; break;
	case 'ч': cout << "ch"; break;
	case 'ш': cout << "sh"; break;
	case 'щ': cout << "sch"; break;
	case 'ъ': cout << ""; break;
	case 'ы': cout << "y"; break;
	case 'ь': cout << ""; break;
	case 'э': cout << "e"; break;
	case 'ю': cout << "yu"; break;
	case 'я': cout << "ya"; break;

	case 'A': cout << "А"; break;
	case 'B': cout << "Б"; break;
	case 'C': {
				if (str[i + 1] == 'h')
					{
						cout << "Ч";
						i++;
					}
					else
					cout << "С";
			} break;
	case 'D': cout << "Д"; break;
	case 'E': cout << "Е"; break;
	case 'F': cout << "Ф"; break;
	case 'G': cout << "Г"; break;
	case 'H': cout << "Х"; break;
	case 'I': cout << "И"; break;
	case 'J': cout << "Дж"; break;
	case 'K': cout << "К"; break;
	case 'L': cout << "Л"; break;
	case 'M': cout << "М"; break;
	case 'N': cout << "Н"; break;
	case 'O': cout << "О"; break;
	case 'P': cout << "П"; break;
	case 'Q': cout << "К"; break;
	case 'R': cout << "Р"; break;
	case 'S': {
				if (str[i + 1] == 'h')
					{
						cout << "Ш";
						i++;
					}
					else
						if ((str[i + 1] == 'с') || (str[i + 2] == 'h'))
						{
							cout << "Щ";
							i += 2;
						}
						else
					cout << "С";
			} break;
	case 'T':
			{
				if (str[i + 1] == 's') 
				{
					cout << "Ц";
					i++;
				}else
			cout << "Т";
			} break;
	case 'U': cout << "У"; break;
	case 'V': cout << "В"; break;
	case 'W': cout << "В"; break;
	case 'X': cout << "Кс"; break;
	case 'Y':
			{
				if (str[i + 1] == 'o') 
				{
					cout << "Ё";
					i++;
				}
				else
					if (str[i + 1] == 'i')
					{
						cout << 'Ы';
						i++;
					}
					else
						if (str[i + 1] == 'u')
						{
							cout << 'Ю';
							i++;
						}
						else
							if (str[i + 1] == 'a')
							{
								cout << 'Я';
								i++;
							}else
								cout << "Й"; 
			} break;
		case 'Z': 
				{
					if (str[i + 1] == 'h')
					{
						cout << 'Ж';
							i++;
					}
					else
						cout << "З";} break;


		case 'a': cout << "а"; break;
		case 'b': cout << "б"; break;
		case 'c': {
					if (str[i + 1] == 'h')
						{
							cout << "ч";
							i++;
						}
					else
						cout << "с";
				} break;
		case 'd': cout << "д"; break;
		case 'e': cout << "е"; break;
		case 'f': cout << "ф"; break;
		case 'g': cout << "г"; break;
		case 'h': cout << "х"; break;
		case 'i': cout << "и"; break;
		case 'j': cout << "дж"; break;
		case 'k': cout << "к"; break;
		case 'l': cout << "л"; break;
		case 'm': cout << "м"; break;
		case 'n': cout << "н"; break;
		case 'o': cout << "о"; break;
		case 'p': cout << "п"; break;
		case 'q': cout << "к"; break;
		case 'r': cout << "р"; break;
		case 's': {
				if (str[i + 1] == 'h')
					{
						cout << "ш";
						i++;
					}
					else
						if ((str[i + 1] == 'с') || (str[i + 2] == 'h'))
						{
							cout << "щ";
							i += 2;
						}
						else
					cout << "с";
			} break;
		case 't': {
					if (str[i + 1] == 's')
						{
							cout << "ц";
							i++;
						}
						else
							cout << "т";
				} break;
		case 'u': cout << "у"; break;
		case 'v': cout << "в"; break;
		case 'w': cout << "в"; break;
		case 'x': cout << "кс"; break;
		case 'y': {
					if (str[i + 1] == 'o')
					{
						cout << "ё";
						i++;
					}
					else
						if (str[i + 1] == 'i')
						{
							cout << 'ы';
							i++;
						}
						else
							if (str[i + 1] == 'u')
							{
								cout << 'ю';
								i++;
							}
							else
								if (str[i + 1] == 'a')
								{
									cout << 'я';
									i++;
								}
								else
									cout << "й";
					}break;
		case 'z': 
				{
					if (str[i + 1] == 'h')
					{
						cout << 'ж';
						i++;
					}
					else
						cout << "з"; } break;
		
		
		default:  cout << str[i];

		}
		i++;
	}
}