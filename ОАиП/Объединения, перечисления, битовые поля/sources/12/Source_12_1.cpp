#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

struct NOTEBOOK
{
	string FIO;
	struct DATE_BIRTH
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} date = { 0, 0, 0 };
	string adress;
	string phoneNumber;
	string placeWorkStudy;
	string jobTitle;

	void input()
	{
		unsigned int day = 0, month = 0, year = 0;
		cin.ignore();
		cout << "������� ���" << endl;
		getline(cin, FIO);
	REPEAT_DATE:cout << "������� ���� �������� (00 00 0000)" << endl;
		cin >> day >> month >> year;
		if (day < 32 && month < 13 && year < 2049)
		{
			date.day = day;
			date.month = month;
			date.year = year;
		}
		else
		{
			cout << "������ ����� ����!" << endl;
			goto REPEAT_DATE;
		}
		cin.ignore();
		cout << "������� �����" << endl;
		getline(cin, adress);
		cout << "������� ����� ��������" << endl;
		getline(cin, phoneNumber);
		cout << "������� ����� ������/�����" << endl;
		getline(cin, placeWorkStudy);
		cout << "������� ���������" << endl;
		getline(cin, jobTitle);
	}

	void output()
	{
		cout << "���: " << FIO << endl;
		cout << "���� ��������: " << date.day << " " << date.month << " " << date.year << endl;
		cout << "�����: " << adress << endl;
		cout << "����� ��������: " << phoneNumber << endl;
		cout << "����� ������/�����: " << placeWorkStudy << endl;
		cout << "���������: " << jobTitle << endl;
	}

	void del_note()
	{
		FIO = "";
		date = { 0, 0, 0 };
		adress = "";
		phoneNumber = "";
		placeWorkStudy = "";
		jobTitle = "";
		cout << "������� �������!" << endl;
	}

	bool search(string surname)
	{
		bool flag = false;

		if (this->FIO.find(surname) != -1)
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

	NOTEBOOK note[SIZE];
	int choice;
	do
	{
		cout << "�������� �������: " << endl;
		cout << "1 - �������� �������" << endl;
		cout << "2 - ������� �������" << endl;
		cout << "3 - ������� �������" << endl;
		cout << "4 - ����� ������� �� �������" << endl;
		cout << "5 - �����" << endl;

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
				note[number - 1].input();
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
				note[number - 1].output();
			}
			else
			{
				cout << "������!" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "������� ����� �������" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				note[number - 1].del_note();
			}
			else
			{
				cout << "������!" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "������� �������: ";
			string surname;
			cin.ignore();
			getline(cin, surname);

			for (int i = 0; i < SIZE; i++)
			{
				if (note[i].search(surname))
				{
					note[i].output();
				}
			}
			break;
		}
		}
	} while (choice != 5);
}