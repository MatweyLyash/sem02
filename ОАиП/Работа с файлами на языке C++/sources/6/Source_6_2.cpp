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
//	ofstream fout("fileEx6.txt");
//
//	if (fout.fail())
//	{
//		cout << "������ �������� �����!" << endl;
//		exit(1);
//	}
//	else
//	{
//		cout << "���� ������! (������)" << endl;
//	}
//
//	string str;
//	cout << "������� ������: " << endl;
//
//	getline(cin, str);
//	fout << str;
//	fout.close();
//
//	ifstream fin("fileEx6.txt");
//
//	if (fin.fail())
//	{
//		cout << "������ �������� �����!" << endl;
//		exit(1);
//	}
//	else
//	{
//		cout << "���� ������! (������)" << endl;
//	}
//
//	string tmp;
//
//	while (fin >> tmp)
//	{
//		if (tmp.length() % 2 == 0)
//		{
//			cout << tmp << ' ';
//		}
//	}
//	
//	fout.close();
//}