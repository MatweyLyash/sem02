#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#define SIZE 50

using namespace std;

void success()
{
	cout << "\n�������" << endl;
}
void error()
{
	cout << "\n������" << endl;
}

struct state
{
	string name;
	string capital;
	string population;
	string square;
	string surnamePresident;

	void input()		//���� ���������
	{
		cin.ignore();
		cout << "������� �������� �����������: ";
		getline(cin, name);
		cout << "������� �������� �������: ";
		getline(cin, capital);
		cout << "������� ���������: ";
		getline(cin, population);
		cout << "������� �������: ";
		getline(cin, square);
		cout << "������� ������� ����������: ";
		getline(cin, surnamePresident);
		success();
	}


	void output()		//����� ���������
	{
		cout << "�������� �����������: " << name << endl;
		cout << "������� �����������: " << capital << endl;
		cout << "���������: " << population << endl;
		cout << "�������: " << square << endl;
		cout << "������� ����������: " << surnamePresident << endl;
	}

	bool search(string nameCountry)		//����� ��������� �� �������� ������
	{
		bool flag = false;

		if (this->name == nameCountry)
		{
			output();
			flag = true;
		}

		return flag;
	}

	void del_struct(string nameCountry)		//�������� ���������
	{
		if (this->name == nameCountry)
		{
			name = "";
			capital = "";
			population = "";
			square = "";
			surnamePresident = "";
			success();
		}
	}

	void write(string path)		//������ ��������� � ����
	{
		fstream file;
		file.open(path, fstream::app);		//�������� ����� ��� ������ (���������� � �����)
		if (!file.is_open())
		{
			error();
			exit(1);
		}

		cin.ignore();

		cout << "������� �������� �����������: ";
		getline(cin, name);
		cout << "������� ������� �����������: ";
		getline(cin, capital);
		cout << "������� ���-�� ���������: ";
		getline(cin, population);
		cout << "������� ������� �����������: ";
		getline(cin, square);
		cout << "������� ������� ����������: ";
		getline(cin, surnamePresident);

		file << name << endl;
		file << capital << endl;
		file << population << endl;
		file << square << endl;
		file << surnamePresident << endl;
		file << endl;
		file.close();
		del_struct(name);
	}

	void read(string path)		//������ ��������� �� �����
	{
		fstream file;
		file.open(path, fstream::in);		//�������� ����� ��� ������
		if (!file.is_open())
		{
			error();
			exit(1);
		}

		getline(file, name);
		getline(file, capital);
		getline(file, population);
		getline(file, square);
		getline(file, surnamePresident);
		file.close();
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string path = "data.txt";

	state country[SIZE];
	int choice;
	do
	{
		cout << "�������� �������: " << endl;
		cout << "1 - �������� ������" << endl;
		cout << "2 - ����� ������" << endl;
		cout << "3 - ������� ������" << endl;
		cout << "4 - ����� ������ �� ��������" << endl;
		cout << "5 - ������ ������ � ������ � ����" << endl;
		cout << "6 - ������ ������ � ������ �� �����" << endl;
		cout << "7 - �����" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int counter = 0;
			country[counter].input();
			counter++;
			break;
		}
		case 2:
		{
			for (int i = 0; i < SIZE; i++)
			{
				country[i].output();
			}
			break;
		}
		case 3:
		{
			cout << "������� �������� ������: ";
			string nameCountry;
			cin.ignore();
			getline(cin, nameCountry);
			for (int i = 0; i < SIZE; i++)
			{
				country[i].del_struct(nameCountry);
			}
			break;
		}
		case 4:
		{
			cout << "������� �������� ������: ";
			string nameCountry;
			cin.ignore();
			getline(cin, nameCountry);
			for (int i = 0; i < SIZE; i++)
			{
				country[i].search(nameCountry);
			}
			break;
		}
		case 5:
		{
			country[49].write(path);
		}
		case 6:
		{
			country[49].read(path);
		}
		case 7:
		{
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice != 7);
}