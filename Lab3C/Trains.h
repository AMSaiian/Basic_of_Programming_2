#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <iomanip>

using namespace std;

class Train
{
	private:
		int m_number;
		string m_destination;
		string m_departure;
	public:
		Train();
		Train(int number, string destination, string departure);
		void setNumber(int number);
		void setDestination(string destination);
		void setDeparture(string departure);
		void setNumberRand();
		void setDestinationRand(string cities[], const int size);
		void setDepartureRand();
		int getNumber();
		string getDestination();
		string getDeparture();
		int getDepartureInMin();
};
