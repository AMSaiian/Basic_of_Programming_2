#include "Header.h"
void AddFile(string name, int& rowsorig)
{
	SetConsoleCP(1251);
	fstream input(name, ios::out);
	if (!input.is_open())
	{
		cout << "Ошибка. Файл не создан\n";
	}
	else
	{
		cout << "Создан и открыт файл с названием " << name << " в корне проекта\n";
		cout << "Для записи текста вводите его построчно с помощью Enter.\nДля завершения в последней строке в конце нажмите Ctrl + X и Enter\n\n";
		string row;
		bool flag = true;
		do
		{
			row = "";
			getline(cin, row);
			if (row.find("") != string::npos)
			{
				row.erase(row.length() - 1);
				flag = false;
			}
			rowsorig++;
			input << row << "\n";
		} while (flag);
	}
	input.close();
}

void OutputRows(string name)
{
	fstream output(name, ios::in);
	if (!output.is_open())
	{
		cout << "Ошибка. Файл " << name << " не открыт\n";
	}
	else
	{
		cout << "Файл " << name << " открыт\nСодержимое:\n\n";
		string row;
		while (!output.eof())
		{
			getline(output, row);
			cout << row << endl;
		}
	}
}

void CopyRows(string original, string copy, int& amount, int rowsorig)
{
	fstream buf(original);
	fstream write(copy, ios::out | ios::trunc);
	do
	{
		cout << "Введите количество строк, которые нужно скопировать: ";
		cin >> amount;
		cout << endl;
		cin.ignore(1000, '\n');
	} while (amount > rowsorig || amount <= 0);
	string temp;
	int turn = 0;
	if (rowsorig != amount)
	{
		for (int i = 0; i < rowsorig - amount; i++)
		{
			getline(buf, temp);
			turn = turn + temp.length() + 2;
		}
	}
	buf.seekg(turn, ios::beg);
	while(getline(buf, temp))
	{ 
		write << temp << "\n";
	}
	buf.close();
	write.close();
}

void DeleteRows(string name, int &deleted)
{
	fstream copy(name);
	if (!copy.is_open())
	{
		cout << "Ошибка. Файл " << name << " не открыт\n";
	}
	else
	{
		cout << "Файл " << name << " открыт\n";
		vector<string> sort;
		string temp;
		while (!copy.eof())
		{
			getline(copy, temp);
			sort.push_back(temp);
		}
		vector<string>::iterator it1 = sort.begin() + sort.size() - 1;
		sort.erase(it1);
		copy.close();
		fstream copy(name, ios::out);
		for (int i = 0; i < sort.size(); i++)
		{
			for (int j = i + 1; j < sort.size(); j++)
			{
				while (sort[i] == sort[j])
				{
					vector<string>::iterator it2 = sort.begin() + j;
					sort.erase(it2);
					deleted++;
					if (j == sort.size())
						break;
				}
			}
			copy << sort[i] << "\n";
		}
		copy.close();
	}
}

void AddText(string name)
{
	fstream input(name, ios::app);
	if (!input.is_open())
	{
		cout << "Ошибка. Файл не открыт\n";
	}
	else
	{
		cout << "Открыт файл с названием " << name << " в корне проекта\n";
		cout << "Для записи текста вводите его построчно с помощью Enter.\nДля завершения в последней строке в конце нажмите Ctrl + X и Enter\n\n";
		string row;
		bool flag = true;
		do
		{
			row = "";
			getline(cin, row);
			if (row.find("") != string::npos)
			{
				row.erase(row.length() - 1);
				flag = false;
			}
			input << row << "\n";
		} while (flag);
	}
	input.close();
}