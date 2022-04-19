#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct TimePeriod
{
	int hours;
	int minutes;
	int seconds;
};

class Time
{
private:
	int m_hours;
	int m_minutes;
	int m_seconds;
public:
	Time(int hours, int minutes, int seconds);
	Time(string sTime);
	Time(Time& object);
	void setTimeString(string sTime);
	void setTime(int hours, int minutes, int seconds);
	void setHour(int hours);
	void setMin(int min);
	void setSec(int sec);
	string getTimeString();
	int getHour();
	int getMin();
	int getSec();
	TimePeriod countTimeTo(Time timeTo);
	friend bool operator>(Time time1, Time time2);
	friend void operator++(Time &time);
	friend void operator++(Time &time, int post);
};