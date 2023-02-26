#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

union STUFF
{
	struct HUMAN
	{
		string FIO;
		string education;
		string speciality;
		string subdivision;
		string jobTitle;
		string salary;
		string date;
	};
};

struct HUMAN_RESOURCES_DEPARTMENT
{
	string FIO;
	string education;
	string speciality;
	string subdivision;
	string jobTitle;
	string salary;
	string date;

	void input(STUFF::HUMAN human)
	{
		FIO = human.FIO;
		education = human.education;
		speciality = human.education;
		subdivision = human.subdivision;
		jobTitle = human.jobTitle;
		salary = human.salary;
		date = human.date;
	}

	void output()
	{
		cout << "���: " << FIO << endl;
		cout << "�����������: " << education << endl;
		cout << "�������������: " << speciality << endl;
		cout << "�������������: " << speciality << endl;
		cout << "���������: " << jobTitle << endl;
		cout << "�����: " << salary << endl;
		cout << "���� ����������� �� �����������: " << date << endl;
	}

	bool search(string jobTitle)
	{
		bool flag = false;

		if (this->jobTitle == jobTitle)
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
	STUFF::HUMAN human;
	int choice = 0;
	do
	{
		cout << "�������� �������: " << endl;
		cout << "1 - �������� ����" << endl;
		cout << "2 - ������� ����" << endl;
		cout << "3- ����� ����� �� ���������" << endl;
		cout << "4 - �����" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "������� ����� ���������� �����" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				cin.ignore();
				cout << "������� ���" << endl;
				getline(cin, human.FIO);
				cout << "������� �����������" << endl;
				getline(cin, human.education);
				cout << "������� �������������" << endl;
				getline(cin, human.speciality);
				cout << "������� �������������" << endl;
				getline(cin, human.subdivision);
				cout << "������� ���������" << endl;
				getline(cin, human.jobTitle);
				cout << "������� �����" << endl;
				getline(cin, human.salary);
				cout << "������� ���� ����������� �� �����������" << endl;
				getline(cin, human.date);
				humans[number - 1].input(human);
			}
			else
			{
				cout << "������!" << endl;
			}
			break;
		}
		case 2:
		{
			cout << "������� ����� ���������� �����" << endl;
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
			cout << "������� ���������: ";
			string jobTitle;
			cin.ignore();
			getline(cin, jobTitle);

			for (int i = 0; i < SIZE; i++)
			{
				if (humans[i].search(jobTitle))
				{
					humans[i].output();
				}
			}
			break;
		}
		}
	} while (choice != 4);
}