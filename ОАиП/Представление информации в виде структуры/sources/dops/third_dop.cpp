//#include <iostream>
//#include <Windows.h>
//#include <string>
//#include <iomanip>
//
//#define SIZE 5
//
//using namespace std;
//
//struct SANATORIUM
//{
//	string name;
//	string location;
//	string profile;
//	string numOfVouchers;
//
//	bool search(string searchName)
//	{
//		bool flag = false;
//
//		if (this->name == searchName)
//		{
//			flag = true;
//		}
//
//		return flag;
//	}
//
//	void output()
//	{
//		cout << "�������� ��������� " << name << endl;
//		cout << "������������ ��������� " << location << endl;
//		cout << "������� ��������� " << profile << endl;
//		cout << "���������� ������ " << numOfVouchers << endl;
//	}
//
//	void output_sort()
//	{
//		cout << profile << "\t\t\t|\t" << name << "\t|\t" << location << "\t|\t" << numOfVouchers << endl;
//	}
//};
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	SANATORIUM element[SIZE];
//
//	//������� � ������� �� ������� (�������� ��� ������������� ������� � �������)
//	element[0].name = "�������� ���"; element[0].location = "�����   "; element[0].profile = "������"; element[0].numOfVouchers = "45";
//	element[1].name = "��������"; element[1].location = "�����   "; element[1].profile = "������"; element[1].numOfVouchers = "31";
//	element[2].name = "����������"; element[2].location = "������   "; element[2].profile = "������"; element[2].numOfVouchers = "12";
//	element[3].name = "���������"; element[3].location = "������   "; element[3].profile = "������"; element[3].numOfVouchers = "43";
//	element[4].name = "���������"; element[4].location = "������ "; element[4].profile = "�����"; element[4].numOfVouchers = "39";
//
//	cout << "��������� ������������� ������" << endl;
//	cout << "�������� �������" << "\t|\t" << "��������" << "\t|\t" << "������������" << "\t|\t" << "���-�� ������" << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//		element[i].output_sort();
//	}
//	int choice = 0;
//	string sanName;
//	bool flag = false;
//	do
//	{
//		cout << "������� �������:" << endl;
//		cout << "1 - ����� � ����� ����������" << endl;
//		cout << "2 - �����" << endl;
//		cin >> choice;
//
//		if (choice == 1)
//		{
//			cout << "������� �������� ���������" << endl;
//			cin.ignore();
//			getline(cin, sanName);
//
//			for (int i = 0; i < SIZE; i++)
//			{
//				if (element[i].search(sanName))
//				{
//					element[i].output();
//					flag = true;
//					break;
//				}
//			}
//			if (!flag)
//			{
//				cout << "��������� �� ������!" << endl;
//			}
//		}
//
//	} while (choice != 2);
//}