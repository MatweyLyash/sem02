#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

union DATE_EXAM
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
} date;

struct TEACHERS
{
	string surname;
	string exam;
	struct DATE
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} date_exam = { 0,0,0 };
	

	void input()
	{
		cin.ignore();
		cout << "������� ������� �������������" << endl;
		getline(cin, surname);
		cout << "������� �������� ��������" << endl;
		getline(cin, exam);
		cout << "������� ���� (00 00 0000)" << endl;
		cout << "������� ���� ";
		cin >> date.day;
		if (date.day < 32);
		{
			date_exam.day = date.day;
		}
		cout << "������� ����� ";
		cin >> date.month;
		if (date.month < 13);
		{
			date_exam.month = date.month;
		}
		cout << "������� ��� ";
		cin >> date.year;
		if (date.year < 2049);
		{
			date_exam.year = date.year;
		}

	}

	void output()
	{
		cout << "������� �������������: " << surname << endl;
		cout << "�������� ��������: " << exam << endl;
		cout << "���� ��������: " << date_exam.day << " " << date_exam.month << " " << date_exam.year << endl;
	}

	bool search(string surname)
	{
		bool flag = false;

		if (this->surname == surname)
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

	TEACHERS teacher[SIZE];
	int choice;
	do
	{
		cout << "�������� �������: " << endl;
		cout << "1 - �������� �������������" << endl;
		cout << "2 - ������� ����������" << endl;
		cout << "3 - ����� ������������� �� �������" << endl;
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
				teacher[number - 1].input();
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
				teacher[number - 1].output();
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
			cout << "������� �������: ";
			string surname;
			getline(cin, surname);
			bool flag = false;

			for (int i = 0; i < SIZE; i++)
			{
				if (teacher[i].search(surname))
				{
					teacher[i].output();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "������������� �� ������!" << endl;
			}
			break;
		}
		}
	} while (choice != 4);
}