//#include <iostream>
//#include <fstream>
//#include <string>
//#include <Windows.h>
//
//using namespace std;
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	ofstream fout("dataEx2.txt");
//	if (fout.fail())
//	{
//		cout << "������ �������� ����� dataEx2.txt (������)" << endl;
//		exit(1);
//	}
//	else
//	{
//		cout << "���� ������ ��� ������" << endl;
//	}
//
//	cout << "������� ������" << endl;
//
//	SetConsoleCP(1251);			//��������� ��������� ��� ����� (���������� ����������� ���������� � �����).
//	string str;
//	getline(cin, str);
//	fout << str;
//	fout.close();
//	SetConsoleCP(866);			//��������� ��������� �� ���������.
//
//	cout << "������ ��������, ���� ������" << endl;
//
//	fout.close();
//
//	ifstream fin("dataEx2.txt");
//
//	if (fin.fail())				//�������� �� �������� �����.
//	{
//		cout << "������ �������� ����� dataEx2.txt (������)" << endl;
//		exit(1);
//	}
//	else
//	{
//		cout << "���� ������ ��� ������" << endl;
//	}
//
//	string tmp;
//	int counter = 0;
//	bool flag = false;
//
//	fin >> tmp;
//	for (int i = 0; i < tmp.length(); i++)
//	{
//		if (tmp[i] == ',')
//		{
//			counter++;
//			flag = true;
//		}
//	}
//
//	if (!flag)
//	{
//		cout << "��� �������" << endl;
//	}
//	else
//	{
//		cout << "���-�� ������� " << counter;
//	}
//
//	fin.close();
//}