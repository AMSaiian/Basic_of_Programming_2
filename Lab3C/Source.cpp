#include "Header.h"


void createSchedule(vector<Train>& schedule, string cities[], int size)
{
	int choice;
	do
	{
		int number;
		string destination;
		string departure;
		Train train;
		cout << "\nВведите 1 для добавления поезда вручную.\nВведите 2 для создания поезда случайным образом."
			<< "\nВведите 3 для создания некоторого количества поездов случайным образом.\nВведите 4 для вывода списка поездов"
			<< "\nВведите 5 для завершение работы по созданию списка\nВыбор: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		switch (choice)
		{
			case 1:
				cout << "\nВведите номер поезда: ";
				cin >> number;
				cin.ignore(1000, '\n');
				cout << "Введите место назначения: ";
				getline(cin, destination);
				cout << "Введите время отправления (формат 00-00 - 24-00): ";
				getline(cin, departure);
				train.setNumber(number);
				train.setDestination(destination);
				train.setDeparture(departure);
				schedule.push_back(train);
				sortSchedule(schedule);
				break;
			case 2:
				train.setNumberRand();
				train.setDestinationRand(cities, size);
				train.setDepartureRand();
				schedule.push_back(train);
				sortSchedule(schedule);
				break;
			case 3:
				cout << "\nВведите количество поездов, которое нужно создать случайным образом: ";
				int amount;
				cin >> amount;
				cin.ignore(1000, '\n');
				for (int i = 0; i < amount; i++)
				{
					train.setNumberRand();
					train.setDestinationRand(cities, size);
					train.setDepartureRand();
					schedule.push_back(train);
				}
				sortSchedule(schedule);
				break;
			case 4:
				cout << "\nСписок поездов:\n";
				showSchedule(schedule);
				break;
		}
	} while (choice != 5);
}

void showSchedule(vector<Train> schedule)
{
	for (int i = 0; i < schedule.size(); i++)
	{
		cout << setw(6) << left << schedule[i].getNumber() 
			 << setw(10) << left << schedule[i].getDestination() 
			 << setw(8) << left << schedule[i].getDeparture() << endl;
	}
}

void sortSchedule(vector<Train>& schedule)
{
	for (int i = 0; i < schedule.size() - 1; i++)
	{
		for (int j = 0; j < schedule.size() - 1 - i; j++)
		{
			if (schedule[j].getDepartureInMin() > schedule[j + 1].getDepartureInMin())
				swap(schedule[j], schedule[j + 1]);
		}
	}
}

int findLatest(vector<Train> schedule, string destination, string& timeLatest)
{
	int numberLatest = -1;
	for (int i = schedule.size() - 1; i > -1; i--)
	{
		if (schedule[i].getDestination() == destination)
		{
			numberLatest = schedule[i].getNumber();
			timeLatest = schedule[i].getDeparture();
			break;
		}
	}
	return numberLatest;
}