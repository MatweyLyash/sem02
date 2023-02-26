#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

union NOTE
{
	struct a_note
	{
		string FIO;
		string date;
		string adress;
		string phoneNumber;
		string placeWorkStudy;
		string jobTitle;
	};
};

struct NOTEBOOK
{
	string FIO;
	string date;
	string adress;
	string phoneNumber;
	string placeWorkStudy;
	string jobTitle;

	void input(NOTE::a_note note)
	{
		FIO = note.FIO;
		date = note.date;
		adress = note.adress;
		phoneNumber = note.phoneNumber;
		placeWorkStudy = note.placeWorkStudy;
		jobTitle = note.jobTitle;
	}

	void output()
	{
		cout << "���: " << FIO << endl;
		cout << "���� ��������: " << date << endl;
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

	int choice;
	NOTEBOOK book[SIZE];
	NOTE::a_note note;
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
				cin.ignore();
				cout << "������� ���" << endl;
				getline(cin, note.FIO);
				cout << "������� ���� ��������" << endl;
				getline(cin, note.date);
				cout << "������� �����" << endl;
				getline(cin, note.adress);
				cout << "������� ����� ��������" << endl;
				getline(cin, note.phoneNumber);
				cout << "������� ����� �����/������" << endl;
				getline(cin, note.placeWorkStudy);
				cout << "������� ���������" << endl;
				getline(cin, note.jobTitle);
				book[number - 1].input(note);
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
				book[number - 1].output();
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
				book[number - 1].del_note();
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
				if (book[i].search(surname))
				{
					book[i].output();
				}
			}
			break;
		}
		}
	} while (choice != 5);
}