//#include <iostream>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	ifstream fin("dataFileEx6.txt");
//	ofstream fout("resultFileEx6.txt");
//
//	if (fin.fail() || fout.fail())
//	{
//		cout << "������ �������� ������!" << endl;
//		exit(1);
//	}
//	else
//	{
//		cout << "����� �������!" << endl;
//	}
//
//	cout << "������� ����� ������ ������ ������, ����� ����� ������ ����������: ";
//	int start, end, counter = 0;
//	cin >> start >> end;
//
//	string str;
//	while (!fin.eof())
//	{
//		getline(fin, str);
//		counter++;
//		if (start <= counter && end >= counter)
//		{
//			fout << str << "\n";
//		}
//	}
//	fin.close();
//	fout.close();
//
//	ifstream fileForCount("resultFileEx6.txt");
//
//	if (fileForCount.fail())
//	{
//		cout << "������ �������� ����� resultFileEx6.txt (������)" << endl;
//		exit(1);
//	}
//	else
//	{
//		cout << "���� resultFileEx6.txt ������ ��� ������" << endl;
//	}
//
//	string vowels = "AaEeIiOoUuYy";
//	string tmp;
//	counter = 0;
//
//	while (!fileForCount.eof())
//	{
//		getline(fileForCount, tmp);
//		for (int i = 0; i < tmp.length(); i++)
//		{
//			if (vowels.find(tmp[i]) != -1)
//			{
//				counter++;
//			}
//		}
//	}
//
//	cout << "���������� ������� � ����� " << counter;
//	fileForCount.close();
//}