#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

enum SEX
{
	man = 1, woman
};

struct CITIZENS
{
	string FIO;
	struct BIRTH_DATE
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} date = { 0,0,0 };
	string adress;
	string sex;

	void input()
	{
		cin.ignore();
		cout << "������� ���" << endl;
		getline(cin, FIO);
		cout << "������� ���� �������� (00 00 0000)" << endl;
		unsigned int day = 0, month = 0, year = 0;
		cin >> day >> month >> year;
		if (day < 32 && month < 13 && year < 2049)
		{
			date.day = day;
			date.month = month;
			date.year = year;
		}
		cin.ignore();
		cout << "������� �����" << endl;
		getline(cin, adress);
		cout << "������� ��� (1 - �������, 2 - �������)" << endl;
		int choice = 0;
		switch (choice)
		{
		case SEX::man:
		{
			sex = "�������";
			break;
		}
		case SEX::woman:
		{
			sex = "�������";
			break;
		}
		default:
		{
			cout << "�������� �������" << endl;
			break;
		}
		}
	}

	void output()
	{
		cout << "���: " << FIO << endl;
		cout << "���� ��������:" << date.day << " " << date.month << " " << date.year << endl;
		cout << "�����: " << adress << endl;
		cout << "���: " << sex << endl;
	}

	void del_citizen()
	{
		FIO = "";
		date = { 0,0,0 };
		adress = "";
		sex = "";
	}

	bool search(unsigned int year)
	{
		bool flag = false;

		if (this->date.year == year)
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

	CITIZENS citizen[SIZE];
	int choice;
	do
	{
		cout << "�������� �������: " << endl;
		cout << "1 - �������� ����������" << endl;
		cout << "2 - ������� ���������� � ����������" << endl;
		cout << "3 - ������� ���������� � ����������" << endl;
		cout << "4 - ����� ���������� �� ���� ��������" << endl;
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
				citizen[number - 1].input();
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
				citizen[number - 1].output();
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
				citizen[number - 1].del_citizen();
			}
			else
			{
				cout << "������!" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "������� ��� ��������: ";
			int birthYear;
			bool flag = false;
			cin.ignore();
			cin >> birthYear;

			for (int i = 0; i < SIZE; i++)
			{
				if (citizen[i].search(birthYear))
				{
					citizen[i].output();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "��������� �� ������!" << endl;
			}
			break;
		}
		}
	} while (choice != 5);
}