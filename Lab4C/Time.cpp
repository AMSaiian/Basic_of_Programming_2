#include "Time.h"


Time::Time(int hours = 0, int minutes = 0, int seconds = 0)
{
	if (hours < 24 && minutes < 60 && seconds < 60)
	{
		m_hours = hours;
		m_minutes = minutes;
		m_seconds = seconds;
	}
	else
	{
		cout << "\nПодано неверное время, установленно по умолчанию 00:00:00\n";
		*this = Time();
	}
}

Time::Time(string sTime)
{
	if (sTime.size() == 8)
	{
		int tempHours = stoi(sTime.substr(0, 2));
		int tempMin = stoi(sTime.substr(3, 2));
		int tempSec = stoi(sTime.substr(6, 2));
		if (tempHours < 24 && tempMin < 60 && tempSec < 60)
		{
			m_hours = tempHours;
			m_minutes = tempMin;
			m_seconds = tempSec;
		}
		else
		{
			cout << "\nПодано неверное время, установленно по умолчанию 00:00:00\n";
			*this = Time();
		}
	}
	else
	{
		cout << "\nПодано неверное время, установленно по умолчанию 00:00:00\n";
		*this = Time();
	}
}

Time::Time(Time& object)
{
	m_hours = object.m_hours;
	m_minutes = object.m_minutes;
	m_seconds = object.m_seconds;
}

void Time::setTimeString(string sTime)
{
	if (sTime.size() == 8)
	{
		int tempHours = stoi(sTime.substr(0, 2));
		int tempMin = stoi(sTime.substr(3, 2));
		int tempSec = stoi(sTime.substr(6, 2));
		if (tempHours < 24 || tempMin < 60 || tempSec < 60)
		{
			m_hours = tempHours;
			m_minutes = tempMin;
			m_seconds = tempSec;
		}
		else
		{
			cout << "\nПодано неверное время, установленно по умолчанию 00:00:00\n";
			*this = Time();
		}
	}
	else
	{
		cout << "\nПодано неверное время, установленно по умолчанию 00:00:00\n";
		*this = Time();
	}
}

void Time::setTime(int hours, int minutes, int seconds)
{
	if (hours < 24 && minutes < 60 && seconds < 60)
	{
		m_hours = hours;
		m_minutes = minutes;
		m_seconds = seconds;
	}
	else
	{
		cout << "\nПодано неверное время, установленно по умолчанию 00:00:00\n";
		m_hours = 0;
		m_minutes = 0;
		m_seconds = 0;
	}
}

void Time::setHour(int hours)
{			
	if (hours < 24)
		m_hours = hours;
	else
	{
		cout << "\nВведено неверное значение, установлено по умолчанию 0";
		m_hours = 0;
	}			
}

void Time::setMin(int min)
{
	if (min < 60)
		m_minutes = min;
	else
	{
		cout << "\nВведено неверное значение, установлено по умолчанию 0";
		m_minutes = 0;
	}
}

void Time::setSec(int sec)
{
	if (sec < 60)
		m_seconds = sec;
	else
	{
		cout << "\nВведено неверное значение, установлено по умолчанию 0";
		m_seconds = 0;
	}
}

string Time::getTimeString()
{
	string time = (m_hours > 9 ? to_string(m_hours) : "0" + to_string(m_hours)) + ":"
		+ (m_minutes > 9 ? to_string(m_minutes) : "0" + to_string(m_minutes)) + ":"
		+ (m_seconds > 9 ? to_string(m_seconds) : "0" + to_string(m_seconds));
	return time;
}

int Time::getHour()
{
	return m_hours;
}

int Time::getMin()
{
	return m_minutes;
}

int Time::getSec()
{
	return m_seconds;
}

TimePeriod Time::countTimeTo(Time timeTo)
{
	if (timeTo > *this)
	{
		TimePeriod timeLeft{ 0,0,0 };
		timeLeft.seconds = timeTo.m_seconds - m_seconds;
		if (timeLeft.seconds < 0)
		{
			timeLeft.minutes = -1;
			timeLeft.seconds = 60 + timeLeft.seconds;
		}
		timeLeft.minutes = timeLeft.minutes + timeTo.m_minutes - m_minutes;
		if (timeLeft.minutes < 0)
		{
			timeLeft.hours = -1;
			timeLeft.minutes = 60 + timeLeft.minutes;
		}
		timeLeft.hours = timeLeft.hours + timeTo.m_hours - m_hours;
		return timeLeft;
	}
	else
	{
		cout << "\nНевозможно посчитать временной промежуток, так как указанный момент времени уже наступил";
		return { 0, 0, 0 };
	}
}

bool operator>(Time time1, Time time2)
{
	int time1InSec = 3600 * time1.m_hours + 60 * time1.m_minutes + time1.m_seconds;
	int time2InSec = 3600 * time2.m_hours + 60 * time2.m_minutes + time2.m_seconds;
	if (time1InSec > time2InSec)
		return true;
	else
		return false;
}

void operator++(Time& time)
{
	time.m_minutes++;
	if (time.m_minutes >= 60)
	{
		time.m_hours++;
		time.m_minutes %= 60;
	}
	else
		return;
	if (time.m_hours == 24)
		time.m_hours = 0;
}

void operator++(Time& time, int post)
{
	time.m_seconds++;
	if (time.m_seconds >= 60)
	{
		time.m_minutes++;
		time.m_seconds %= 60;
	}
	else
		return;
	if (time.m_minutes >= 60)
	{
		time.m_hours++;
		time.m_minutes %= 60;
	}
	else
		return;
	if (time.m_hours == 24)
		time.m_hours = 0;
}
