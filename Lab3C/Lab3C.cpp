#include "Trains.h"
#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	string cities[9] {"Киев", "Сумы", "Харьков", "Чернигов", "Запорожье", "Одесса", "Львов", "Луцк", "Днепро"};
	vector<Train> schedule;
	createSchedule(schedule, cities, 9);
	string timeLatest;
	string destination;
	cout << "\nВыберите пункт назначения для поиска последнего поезда: ";
	getline(cin, destination);
	int latestNumber = findLatest(schedule, destination, timeLatest);
	if (latestNumber != -1)
	{
		cout << "\nСамый поздний поезд по указанному направлению имеет номер " << latestNumber;
		cout << " и отправляется в " << timeLatest;
	}
	else
		cout << "\nПоезда по данному направлению в этот день не отправлялись";
}