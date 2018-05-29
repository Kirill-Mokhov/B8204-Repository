#include <stdio.h>
#include <string>
#include <iostream>
#include <locale.h>

using namespace std;

struct alphabet{
	string cyr;
	string lat;
};

alphabet voc[66] = {
    { "А", "A" },	
	{ "Б", "B" },	
	{ "В", "V" },
	{ "Г", "G" },	
	{ "Д", "D" },	
	{ "Е", "Ye" },
	{ "Ё", "Yo" },	
	{ "Ж", "Zh" },	
	{ "З", "Z" },
	{ "И", "I" },	
	{ "К", "K" },	
	{ "Л", "L" },
	{ "М", "M" },	
	{ "Н", "N" },	
	{ "О", "O" },
	{ "П", "P" },	
	{ "Р", "R" },	
	{ "С", "S" },
	{ "Т", "T" },	
	{ "У", "U" },	
	{ "Й", "Y" },
	{ "Ф", "F" },	
	{ "Х", "H" },	
	{ "Ч", "Ch" },
	{ "Ш", "Sh" },	
	{"Щ", "Shc"},	
	{ "Ц", "C" },
	{"Ъ", "\'\'"}, 
	{ "Ь", "'" },	
	{ "Ы", "Ii" },
	{ "Э", "E" },	
	{ "Ю", "Yu" },	
	{ "Я", "Ya" },
	{ "а", "a" },	
	{ "б", "b" },	
	{ "в", "v" },
	{ "г", "g" },	
	{ "д", "d" },	
	{ "е", "ye" },
	{ "ё", "yo" },	
	{ "ж", "zh" },	
	{ "з", "z" },
	{ "и", "i" },	
	{ "й", "y" },    
	{ "к", "k" },
    { "л", "l" },   
	{ "м", "m" },    
	{ "н", "n" },
	{ "о", "o" },	
	{ "п", "p" },	
	{ "р", "r" },
	{ "с", "s" },	
	{ "т", "t" },	
	{ "у", "u" },
	{ "ф", "f" },	
	{ "х", "h" },	
	{ "ч", "ch" },
	{ "ш", "sh" },	
	{ "щ", "shc" },	
	{ "ц", "c" },
	{ "ъ", "\'\'" },
	{ "ь", "'" },	
	{ "ы", "ii" },
	{ "э", "e" },	
	{ "ю", "yu" },	
	{ "я", "ya" }
};

string cyrToLat(string s){
    int i(0);
	while((i < 66) && !(voc[i].cyr == s)) i++;
    if(i == 66) return s;
    else return voc[i].lat;
}

string translit(string s){
	string result = "";
    string buff = "00";
	for(int i = 0; i < s.length(); i+=2){
        buff[0] = s[i]; buff[1] = s[i+1];
        if(cyrToLat(buff) == buff){
            buff[0] = s[i]; buff[1] = '\0';
            result += cyrToLat(buff);
            i--;
        }else result += cyrToLat(buff);
	}
	return result;
}

int main(){
    setlocale(LC_ALL, "Russian");
    string input = "Молодой человек пройдемте";
	cout << translit(input) << endl;
	return 0;
}
