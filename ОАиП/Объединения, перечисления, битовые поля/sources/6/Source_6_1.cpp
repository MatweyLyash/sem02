#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

enum BRAND
{
	Audi = 1, Bentley, BMW, Lexus, MercedesBenz
};

struct NOTEBOOK_CAR
{
	string brand;
	string color;
	string WIN;
	struct DATEISSUE
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} dateIssue = { 0,0,0 };
	string type;
	string inspectionDate;
	string owner;

	void input()
	{
		cin.ignore();
		cout << "�������� ����� ���� (1 - AUDI, 2 - Bentley, 3 - BMW, 4 - Lexus, 5 - MercedesBenz)" << endl;
		unsigned int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case BRAND::Audi:
		{
			brand = "Audi";
			break;
		}
		case BRAND::Bentley:
		{
			brand = "Bentley";
			break;
		}
		case BRAND::BMW:
		{
			brand = "BMW";
			break;
		}
		case BRAND::Lexus:
		{
			brand = "Lexus";
			break;
		}
		case BRAND::MercedesBenz:
		{
			brand = "Mercedes-Benz";
			break;
		}
		default:
		{
			cout << "������ �������� �������" << endl;
			break;
		}
		}
		cin.ignore();
		cout << "������� ���� ����" << endl;
		getline(cin, color);
		cout << "������� WIN" << endl;
		getline(cin, WIN);
	REPEAT_DATE:cout << "������� ���� ������� ���� (00 00 0000)" << endl;
		unsigned int day = 0, month = 0, year = 0;
		cin >> day >> month >> year;
		if (day < 32 && month < 13 && year < 2049)
		{
			dateIssue.day = day;
			dateIssue.month = month;
			dateIssue.year = year;
		}
		else
		{
			cout << "������ ����� ����!" << endl;
			goto REPEAT_DATE;
		}
		cin.ignore();
		cout << "������� ��� ������ (�����, ��������� � �.�.)" << endl;
		getline(cin, type);
		cout << "������� ���� ���������� ���.�������" << endl;
		getline(cin, inspectionDate);
		cout << "������� ���������" << endl;
		getline(cin, owner);
	}

	void output()
	{
		cout << "����� ����: " << brand << endl;
		cout << "���� ����: " << color << endl;
		cout << "WIN ����: " << WIN << endl;
		cout << "���� ������� ����: " << dateIssue.day << " " << dateIssue.month << " " << dateIssue.year << endl;
		cout << "��� ������: " << type << endl;
		cout << "���� ���������� ���.������� " << inspectionDate << endl;
		cout << "�������� ����: " << owner << endl;
	}

	void del_note()
	{
		brand = "";
		color = "";
		WIN = "";
		dateIssue = { 0,0,0 };
		type = "";
		inspectionDate = "";
		owner = "";
	}

	bool search(string WIN)
	{
		bool flag = false;

		if (this->WIN == WIN)
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

	NOTEBOOK_CAR note_car[SIZE];
	int choice;
	do
	{
		cout << "�������� �������: " << endl;
		cout << "1 - �������� �������" << endl;
		cout << "2 - ������� �������" << endl;
		cout << "3 - ������� �������" << endl;
		cout << "4 - ����� ������� �� WIN" << endl;
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
				note_car[number - 1].input();
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
				note_car[number - 1].output();
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
				note_car[number - 1].del_note();
			}
			else
			{
				cout << "������!" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "������� WIN: ";
			string WIN;
			cin.ignore();
			getline(cin, WIN);

			for (int i = 0; i < SIZE; i++)
			{
				if (note_car[i].search(WIN))
				{
					note_car[i].output();
				}
			}
			break;
		}
		}
	} while (choice != 5);
}