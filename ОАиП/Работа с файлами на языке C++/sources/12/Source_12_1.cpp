#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream fin("FILE1.txt");
	ofstream fout("FILE2.txt");

	if (fin.fail())				//�������� �� �������� ������ (������� �� ����).
	{
		cout << "������ �������� ����� FILE1.txt" << endl;
		exit(1);
	}
	if (fout.fail())
	{
		cout << "������ �������� ����� FILE2.txt" << endl;
		exit(1);
	}
	if (!fout.fail() && !fin.fail())
	{
		cout << "����� �������!" << endl;
	}

	string word, str;

	fin >> word;			//���������� ������� ����� �� �����.
	getline(fin, str);		//���������� ������ ������ �� �����.

	fout << word << str << "\n";	//������ ������ ������ � ����, �.�. ��� �� ��������� �������� ������ �����.
	while (!fin.eof())
	{
		getline(fin, str);				//���������� ������ �� �����.
		if (str.find(word) != -1)		//�������� �� ������� ����� � ������.
		{
			fout << str << "\n";
		}
	}

	cout << "������ �������� � ���� FILE2.txt" << endl;

	fin.close();
	fout.close();

	ifstream fileForCount("FILE2.txt");

	if (fileForCount.fail())				//�������� �� �������� �����.
	{
		cout << "������ �������� ����� FILE2.txt (������)" << endl;
		exit(1);
	}
	if (!fileForCount.fail())
	{
		cout << "���� FILE2.txt ������ ��� ������" << endl;
	}

	int counter = 0;
	char ch;
	
	while (!fileForCount.eof())
	{
		fileForCount.get(ch);
		if (ch == '\n')
		{
			counter++;
		}
	}

	fileForCount.close();

	ifstream fileForOutput("FILE2.txt");
	
	for (int i = 0; i < (counter - 1); i++)
	{
		getline(fileForOutput, str);				//���������� str �������� ��������� ������ ����� (����� \n, �.�. counter - 1).
	}

	string consonant = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxYyZz";	//��� ��������� ����. ��. (Y ��� ����. ��� � ��.)
	counter = 0;
	
	for (int i = 0; i < str.length(); i++)
	{
		if (consonant.find(str[i]) != -1)		//�������� �� ������� ��������� � ������.
		{
			counter++;
		}
	}

	cout << "���������� ��������� ���� � ��������� ������ ����� FILE2.txt = " << counter;

	fileForOutput.close();
}