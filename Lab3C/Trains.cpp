#include "Trains.h"

Train::Train()
{
}

Train::Train(int number, string destination, string departure)
{
	m_number = number;
	m_destination = destination;
	m_departure = departure;
}

void Train::setNumber(int number)
{
	m_number = number;
}

void Train::setDestination(string destination)
{
	m_destination = destination;
}

void Train::setDeparture(string departure)
{
	int tempHour = stoi(departure.substr(0, 2));
	int tempMin = stoi(departure.substr(3, 2));
	if (tempHour < 24 && tempMin < 60)
		m_departure = departure;
	else
	{
		cout << "\n”казано неверное врем€, врем€ будет указано автоматически случайным образом\n";
		setDepartureRand();
	}
}

void Train::setNumberRand()
{
	m_number = rand() % 900 + 100;
}

void Train::setDestinationRand(string cities[], const int size)
{
	m_destination = cities[rand() % size];
}

void Train::setDepartureRand()
{
	int tempHour = rand() % 24;
	int tempMin = rand() % 60;
	m_departure = ((tempHour < 10) ? "0" : "") + to_string(tempHour) + "-" + ((tempMin < 10) ? "0" : "") + to_string(tempMin);
}

int Train::getNumber()
{
	return m_number;
}

string Train::getDestination()
{
	return m_destination;
}

string Train::getDeparture()
{
	return m_departure;
}

int Train::getDepartureInMin()
{
	int timeInMin = stoi(m_departure.substr(0, 2)) * 60 + stoi(m_departure.substr(3, 2));
	return timeInMin;
}
