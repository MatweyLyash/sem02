#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

enum JOB_TITLE
{
	CEO = 1, CFO, CVO, COO, CIO
};

struct HUMAN_RESOURCES_DEPARTMENT
{
	string FIO;
	string education;
	string speciality;
	string subdivision;
	string jobTitle;
	string salary;
	struct DATE
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} date = { 0,0,0 };

	void input()
	{
		cin.ignore();
		cout << "������� ���" << endl;
		getline(cin, FIO);
		cout << "������� �����������" << endl;
		getline(cin, education);
		cout << "������� �������������" << endl;
		getline(cin, speciality);
		cout << "������� �������������" << endl;
		getline(cin, subdivision);
		cout << "������� ��������� (1 - CEO, 2 - CFO, 3 - CVO, 4 - COO, 5 - CIO" << endl;
		unsigned int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case JOB_TITLE::CEO:
		{
			jobTitle = "����������� ��������";
			break;
		}
		case JOB_TITLE::CFO:
		{
			jobTitle = "���������� ��������";
			break;
		}
		case JOB_TITLE::CVO:
		{
			jobTitle = "�������������� ��������";
			break;
		}
		case JOB_TITLE::COO:
		{
			jobTitle = "������� ������������ ��������";
			break;
		}
		case JOB_TITLE::CIO:
		{
			jobTitle = "���. ������������ ��������� �� IT";
			break;
		}
		default:
		{
			cout << "������ �������� �������" << endl;
			break;
		}
		}
		cin.ignore();
	REPEAT_DATE:cout << "������� ���� (00 00 0000)" << endl;
		unsigned int day = 0, month = 0, year = 0;
		cin >> day >> month >> year;
		if (day < 32 && month < 13 && year < 2049)
		{
			date.day = day;
			date.month = month;
			date.year = year;
		}
		else
		{
			cout << "���� ������� �������!" << endl;
			goto REPEAT_DATE;
		}
	}

	void output()
	{
		cout << "���: " << FIO << endl;
		cout << "�����������: " << education << endl;
		cout << "�������������: " << speciality << endl;
		cout << "�������������: " << subdivision << endl;
		cout << "���������: " << jobTitle << endl;
		cout << "�����: " << salary << endl;
		cout << "���� ����������� �� �����������: " << date.day << " " << date.month << " " << date.year << endl;
	}

	void del_data()
	{
		FIO = "";
		education = "";
		speciality = "";
		subdivision = "";
		jobTitle = "";
		salary = "";
		date = { 0,0,0 };
	}

	bool search(unsigned int exp)
	{
		//2023 - ������� ��� => ���� ����������� ������������ ���������� ����. �������� ����� ����� � �����
		unsigned int experience = 2023 - date.year;
		bool flag = false;

		if (experience == exp)
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

	HUMAN_RESOURCES_DEPARTMENT humans[SIZE];
	int choice;
	do
	{
		cout << "�������� �������: " << endl;
		cout << "1 - �������� ����" << endl;
		cout << "2 - ������� ����" << endl;
		cout << "3 - ������� ����" << endl;
		cout << "4 - ����� ����� �� �����" << endl;
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
				humans[number - 1].input();
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
				humans[number - 1].output();
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
				humans[number - 1].del_data();
			}
			else
			{
				cout << "������!" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "������� ����: ";
			unsigned int experience;
			bool flag = false;
			cin.ignore();
			cin >> experience;

			for (int i = 0; i < SIZE; i++)
			{
				if (humans[i].search(experience))
				{
					humans[i].output();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "���� � ����� ������ �� ������!" << endl;
			}
			break;
		}
		}
	} while (choice != 5);
}