#include "Header.h"

void CreateAndFillFile(string path)
{
	ofstream out(path, ios::out);
	string words;
	cout << "������� �����, ������� ����� �������� � ���� (����� ������):\n";
	getline(cin, words);
	out << words;
	out.close();
}

void GetLetter(char* letter)
{
	do
	{
		cout << "������� ������ ����� ����: ";
		cin >> *letter;
	} while (!(('A' <= *letter && *letter <= 'Z') || ('a' <= *letter && *letter <= 'z')
			|| ('�' <= *letter && *letter <= '�') || ('�' <= *letter && *letter <= '�')));
}
