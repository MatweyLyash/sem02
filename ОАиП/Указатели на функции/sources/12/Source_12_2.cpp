////������ ����� ���� (������� �� ������ �������)
//#include <iostream>
//
//using namespace std;
//
//bool check(int num, int first, ...)			//���������� 1, ���� ���� �������������. ���������� 0, ���� ��� �������������.
//{
//	int* ptr = &first;
//	int counter = 0;
//
//	for (int i = 0; i < num; i++)
//	{
//
//		if (*(ptr + i) > 0)
//		{
//			counter++;
//		}
//		//cout << *(ptr+i) << "\t" << (ptr+i) << endl;
//		ptr++;
//	}
//	//cout << counter << endl;
//	if (counter == num)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//void deleting_negative(int num, int first, ...)		//�������� ������������� (������ �� 0)
//{
//	int* ptr = &first, * arr = new int[num], * newArr = new int[num];
//	int counter = 0;
//
//	cout << "�������������� ������" << endl;
//	for (int i = 0; i < num; i++)
//	{
//		*(arr + i) = *(ptr + i);		//������ ���������� � ������������ ������.
//		ptr++;
//
//		cout << *(arr + i) << " ";
//
//		if (*(arr + i) < 0)				//������� ������������� ���������.
//		{
//			counter++;
//		}
//	}
//	cout << endl;
//	int j = 0;
//	*newArr = *arr;								//������ ������� �������� � ����� ������.
//	for (int i = 0; i < num; i++)
//	{
//		if (*(arr + i) >= 0)
//		{
//			*(newArr + j) = *(arr + i);			//������ ������������� � ����� ������.
//			j++;
//		}
//	}
//	
//	int position = num - counter;		//������� ������� �������������� ��������.
//	for (int i = 0; i < counter; i++)
//	{
//		*(newArr + position) = 0;		//������ ����� � ����� �������.
//		position++;
//	}
//
//	cout << "���������" << endl;
//	for (int i = 0; i < num; i++)
//	{
//		cout << *(newArr + i) << " ";
//	}
//	delete[] arr, newArr;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	if (check(5, -1, -2, -3, -4, 5))
//	{
//		cout << "���� �������������" << endl;
//
//		deleting_negative(5, -1, -2, -3, -4, 5);		//����� ������� �������� �������������, ��������� ������� �� ��, ��� � � ������� check.
//	}
//	else
//	{
//		cout << "��� �������������" << endl;
//	}
//}