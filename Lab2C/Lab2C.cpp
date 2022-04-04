#include "Header.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	do
	{
		cout << "\nВведите:\n1 для ввода нового клиента\n2 для вывода списка клиентов\n"
			<< "3 для очистки списка\n4 для завершения работы и подсчета свободных промежутков: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		cout << endl;
		switch(choice)
		{
			case 1:
				AddClient();
				break;
			case 2:
				CheckTimeTable();
				break;
			case 3:
				cout << "\nСписок удален\n";
				fstream deletetimetable("timetable.txt", ios::out | ios::trunc);
				deletetimetable.close();
		}
	} while (choice != 4);
	int am = 0;
	int pm = 0;
	CountFreePeriods(am, pm);
}

