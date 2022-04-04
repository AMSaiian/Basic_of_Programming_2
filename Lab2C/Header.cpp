#include "Header.h"
struct Client
{
	char name[30];
	char timein[6];
	char timeout[6];
};

struct PersonPeriod
{
	int persontimeinmin;
	int persontimeoutmin;
};

void AddClient()
{
	Client person;
	cout << "������� ��� �������: ";
	gets_s(person.name);
	cout << "������� ����� ������ ������������ (� ������� 00:00 - 23:59): ";
	gets_s(person.timein);
	cout << "������� ����� ����� ������������ (� ������� 00:00 - 23:59): ";
	gets_s(person.timeout);
	cout << endl;
	if (CheckDoubles(person))
	{
		return;
	}
	else
	{
		fstream addclient("timetable.txt", ios::app | ios::binary);
		if (!addclient.is_open())
		{
			cout << "���� �� ������\n";
			return;
		}
		else
		{
			cout << "���� �� ������� �������� ������ ��� ������ ������������ �������\n";
			addclient.write((char*)&person, sizeof(Client));
			addclient.close();
			CheckTimeTable();
		}
	}
}

bool CheckDoubles(Client& person)
{
	fstream findconflict("timetable.txt", ios::in | ios::binary);
	if (!findconflict.is_open())
	{
		cout << "���� �� ������\n";
		return true;
	}
	else
	{
		cout << "���� �� ������� ����������� �������� ������ ��� �������� �������� � ������������ �������\n";
		bool conflict = false;
		string stimein = string(person.timein);
		string stimeout = string(person.timeout);
		int timeinmin = stoi(stimein.substr(0, 2)) * 60 + stoi(stimein.substr(3, 2));
		int timeoutmin = stoi(stimeout.substr(0, 2)) * 60 + stoi(stimeout.substr(3, 2));
		if ((timeinmin <= timeoutmin) && (timeinmin >= 540) && (timeoutmin <= 1020))
		{
			Client added;
			while (findconflict.read((char*)&added, sizeof(Client)))
			{
				string satimein = string(added.timein);
				string satimeout = string(added.timeout);
				int atimeinmin = stoi(satimein.substr(0, 2)) * 60 + stoi(satimein.substr(3, 2));
				int atimeoutmin = stoi(satimeout.substr(0, 2)) * 60 + stoi(satimeout.substr(3, 2));
				if (timeinmin < atimeoutmin)
				{
					conflict = true;
					findconflict.close();
					break;
				}
			}
			findconflict.close();
			if (conflict)
			{
				cout << "\n�������� ������\n������ �� �������\n";
			}
			return conflict;
		}
		else
		{
			cout << "\n������� ������������ �����\n������ �� �������\n";
			conflict = true;
			return conflict;
		}
	}
}

void CheckTimeTable()
{
	fstream timetable("timetable.txt", ios::in);
	if (!timetable.is_open())
	{
		cout << "���� �� ������\n";
		return;
	}
	else
	{
		cout << "���� �� ������� �������� ������ ��� ������\n";
		Client added;
		cout << "\n������ ��������:\n";
		while (timetable.read((char*)&added, sizeof(Client)))
		{
			cout << added.name << "   " << added.timein << " - " << added.timeout << endl;
		}
		timetable.close();
	}
}

void CountFreePeriods(int &am, int &pm)
{
	fstream count("timetable.txt", ios::in);
	if (!count.is_open())
	{
		cout << "���� �� ������\n";
		return;
	}
	else
	{
		cout << "���� �� ������� �������� ������ ��� ������ ��������� ��������\n";
		Client person;
		PersonPeriod period;
		vector<PersonPeriod> list;
		while (count.read((char*)&person, sizeof(Client)))
		{
			string persontimein = string(person.timein);
			string persontimeout = string(person.timeout);
			period.persontimeinmin = stoi(persontimein.substr(0, 2)) * 60 + stoi(persontimein.substr(3, 2));
			period.persontimeoutmin = stoi(persontimeout.substr(0, 2)) * 60 + stoi(persontimeout.substr(3, 2));
			list.push_back(period);
		}
		if (!list.empty())
		{
			if (list.size() == 1)
			{
				if (list[0].persontimeinmin == 540 && list[0].persontimeoutmin == 720)
					pm++;
				else if (list[0].persontimeinmin == 720 && list[0].persontimeoutmin == 1020)
					am++;
				else if (list[0].persontimeinmin > 540 && list[0].persontimeoutmin < 720)
				{
						am += 2;
						pm++;
				}
				else if (list[0].persontimeinmin > 720 && list[0].persontimeoutmin < 1020)
				{
					am++;
					pm += 2;
				}
				else if (list[0].persontimeinmin != 540 && list[0].persontimeoutmin != 1020)
				{
					am++;
					pm++;
				}
			}
			else
			{
				if (list[0].persontimeinmin != 540)
					am++;
				for (int i = 0; i < list.size() - 1; i++)
				{
					if (list[i].persontimeoutmin != list[i + 1].persontimeinmin)
					{
						if (list[i].persontimeoutmin < 720 && list[i + 1].persontimeinmin > 720)
						{
							am++;
							pm++;
						}
						else if (list[i].persontimeoutmin < 720)
						{
							am++;
						}
						else
							pm++;
					}
				}
				if (list[list.size() - 1].persontimeoutmin != 1020)
					pm++;
			}
		}
		else
		{
			am++;
			pm++;
		}
	}
	cout << "��������� �������� � ������ �������� ���: " << am << "; �� ������: " << pm;
}