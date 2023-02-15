//#include <iostream>
//#include <string>
//
//#define SIZE 50
//
//using namespace std;
//
//struct student
//{
//	string FIO;
//	string numberOfExams;
//	string marks;
//
//	void input()		//���� ���������
//	{
//		cin.ignore();
//		cout << "������� ��� ��������: ";
//		getline(cin, FIO);
//		cout << "������� ���-�� ���������: ";
//		getline(cin, numberOfExams);
//		cout << "������� ������ (����� ������): ";
//		getline(cin, marks);
//	}
//
//
//	void output()		//����� ���������
//	{
//		cout << "���: " << FIO << endl;
//		cout << "���-�� ���������: " << numberOfExams << endl;
//		cout << "������: " << marks << endl;
//	}
//
//	bool search(string name)		//����� ��������� �� ���
//	{
//		bool flag = false;
//
//		if (this->FIO == name)
//		{
//			flag = true;
//		}
//
//		return flag;
//	}
//
//	void del_struct(string name)		//�������� ���������
//	{
//		if (this->FIO == name)
//		{
//			FIO = "";
//			numberOfExams = "";
//			marks = "";
//			cout << "������� �������" << endl;
//		}
//	}
//
//	bool checkMarks()			//�������� ������ ��������
//	{
//		bool flag = false;
//		int numberOfMarks = 0, positiveMarks = 0;
//
//		for (int i = 0; i < marks.length(); i++)
//		{
//			if (marks[i] != ' ' && marks[i] != '\n' && marks[i] != '\0')
//			{
//				numberOfMarks++;
//				if (marks[i] == '4' || marks[i] == '5')
//				{
//					positiveMarks++;
//				}
//			}
//		}
//		if (positiveMarks == numberOfMarks)
//		{
//			flag = true;
//		}
//
//		return flag;
//	}
//
//	bool checkStudent()		//�������� �� ������������� ��������
//	{
//		bool flag = false;
//
//		if (this->FIO != "")
//		{
//			flag = true;
//		}
//
//		return flag;
//	}
//};
//
//float result(student student[SIZE])
//{
//	float result = 0, numAllStudents = 0, numGoodStudents = 0;
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		if (student[i].checkStudent())
//		{
//			numAllStudents++;
//			if (student[i].checkMarks())
//			{
//				numGoodStudents++;
//			}
//		}
//	}
//
//	result = (numGoodStudents / numAllStudents) * 100;
//
//	return result;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	int choice = 0;
//	student student[SIZE];
//
//	do
//	{
//		cout << "�������� �������: " << endl;
//		cout << "1 - �������� ���������� � ��������" << endl;
//		cout << "2 - ����� ���������� � ��������" << endl;
//		cout << "3 - ������� ���������� � ��������" << endl;
//		cout << "4 - ����� �������� �� ���" << endl;
//		cout << "5 - �������� ������ ��������" << endl;
//		cout << "6 - ��������� ����� ���������, ������� �������� �� 4 � 5, � ������ ����� ���������, � ���������" << endl;
//		cout << "7 - �����" << endl;
//
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//		{
//			cout << "������� ���-�� ��������� �� ������ ��������:" << endl;
//
//			int num = 0;
//			cin >> num;
//
//			for (int i = 0; i < num; i++)
//			{
//				student[i].input();
//			}
//			break;
//		}
//		case 2:
//		{
//			for (int i = 0; i < SIZE; i++)
//			{
//				if (student[i].checkStudent())
//				{
//					student[i].output();
//				}
//			}
//			break;
//		}
//		case 3:
//		{
//			cout << "������� ��� ��������: ";
//			string name;
//			cin.ignore();
//			getline(cin, name);
//			for (int i = 0; i < SIZE; i++)
//			{
//				student[i].del_struct(name);
//			}
//			break;
//		}
//		case 4:
//		{
//			cout << "������� ��� ��������: ";
//			string name;
//			bool flag;
//			cin.ignore();
//			getline(cin, name);
//			for (int i = 0; i < SIZE; i++)
//			{
//				flag = student[i].search(name);
//				if (flag)
//				{
//					student[i].output();
//					break;
//				}
//			}
//			if (!flag)
//			{
//				cout << "�� �������" << endl;
//			}
//			break;
//		}
//		case 5:
//		{
//			cout << "������� ��� ��������: ";
//			string name;
//			bool flag, check;
//			cin.ignore();
//			getline(cin, name);
//			for (int i = 0; i < SIZE; i++)
//			{
//				flag = student[i].search(name);
//				if (flag)
//				{
//					if (student[i].checkMarks())
//					{
//						cout << "� �������� ������ 4 � 5" << endl;
//					}
//					else
//					{
//						cout << "� �������� ���� ������ ������ ����� 4 � 5" << endl;
//					}
//					break;
//				}
//			}
//			if (!flag)
//			{
//				cout << "������� �� ������" << endl;
//			}
//			break;
//		}
//		case 6:
//		{
//			cout << "��������� ����� ���������, ������� �������� �� 4 � 5, � ������ ����� ��������� = " << result(student) << " %" << endl;
//		}
//		case 7:
//		{
//			break;
//		}
//		}
//
//	} while (choice != 7);
//}