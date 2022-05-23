#include "Header.h"

void CreateAndFillFile(string path)
{
	ofstream out(path, ios::out);
	string words;
	cout << "Введите слова, которые будут записаны в файл (через пробел):\n";
	getline(cin, words);
	out << words;
	out.close();
}

void GetLetter(char* letter)
{
	do
	{
		cout << "Введите первую букву слов: ";
		cin >> *letter;
	} while (!(('A' <= *letter && *letter <= 'Z') || ('a' <= *letter && *letter <= 'z')
			|| ('А' <= *letter && *letter <= 'Я') || ('а' <= *letter && *letter <= 'я')));
}
