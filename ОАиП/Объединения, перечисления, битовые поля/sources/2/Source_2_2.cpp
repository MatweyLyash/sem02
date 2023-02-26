#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

union TIME
{
	unsigned int hours;
	unsigned int minutes;
};

struct TRAINS
{
	string number;
	string station;
	string travel_days;
	struct DEPARTURE_TIME
	{
		unsigned int hours : 5;
		unsigned int minutes : 6;
	} departure_time = { 0,0 };
	struct ARRIVAL_TIME
	{
		unsigned int hours : 5;
		unsigned int minutes : 6;
	} arrival_time = { 0,0 };


	void input()
	{
		cin.ignore();
		cout << "������� ����� ������" << endl;
		getline(cin, number);
		cout << "������� ����� ����������" << endl;
		getline(cin, station);
		cout << "������� ��� ����������" << endl;
		getline(cin, travel_days);
		TIME time{};
		cout << "������� ����� �����������" << endl;
		cout << "������� ���" << endl;
		cin >> time.hours;
		if (time.hours < 25)
		{
			departure_time.hours = time.hours;
		}
		cout << "������� ������" << endl;
		cin >> time.minutes;
		if (time.minutes < 61)
		{
			departure_time.minutes = time.minutes;
		}
		cout << "������� ����� ��������" << endl;
		cout << "������� ���" << endl;
		cin >> time.hours;
		if (time.hours < 25)
		{
			arrival_time.hours = time.hours;
		}
		cout << "������� ������" << endl;
		cin >> time.minutes;
		if (time.minutes < 61)
		{
			arrival_time.minutes = time.minutes;
		}
	}

	void output()
	{
		cout << "����� ������: " << number << endl;
		cout << "����� ����������: " << station << endl;
		cout << "��� ����������: " << travel_days << endl;
		cout << "����� �����������: " << departure_time.hours << ":" << departure_time.minutes << endl;
		cout << "����� ��������: " << arrival_time.hours << ":" << arrival_time.minutes << endl;
	}

	bool search(string station)
	{
		bool flag = false;

		if (this->station == station)
		{
			flag = true;
		}

		return flag;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TRAINS train[SIZE];
	int choice;
	do
	{
		cout << "�������� �������: " << endl;
		cout << "1 - �������� ���������� � ������" << endl;
		cout << "2 - ������� ����������" << endl;
		cout << "3 - ����� ������ �� ������ ����������" << endl;
		cout << "4 - �����" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "������� ����� ������ �������" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				train[number - 1].input();
			}
			else
			{
				cout << "������!" << endl;
			}
			break;
		}
		case 2:
		{
			cout << "������� ����� �������" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				train[number - 1].output();
			}
			else
			{
				cout << "������!" << endl;
			}
			break;
		}
		case 3:
		{
			cin.ignore();
			cout << "������� ����� ����������: ";
			string station;
			getline(cin, station);
			bool flag = false;

			for (int i = 0; i < SIZE; i++)
			{
				if (train[i].search(station))
				{
					train[i].output();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "����� �� ������!" << endl;
			}
			break;
		}
		}
	} while (choice != 4);
}