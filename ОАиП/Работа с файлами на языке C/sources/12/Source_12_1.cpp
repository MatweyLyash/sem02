//������ �������.
#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	
	FILE* data_file, *result_file;
	
	fopen_s(&data_file, "dataex1.txt", "r");
	fopen_s(&result_file, "resultex1.txt", "w");

	if (data_file == NULL || result_file == NULL)
	{
		perror("������ �������� ������\n");
		return EXIT_FAILURE;
	}
	else 
	{
		printf("����� �������\n");
	}
	
	fseek(data_file, 0, SEEK_END);			//����������� ������� ����������� ����� � ������� �������� ��������� � ����� �����.
	long fsize = ftell(data_file);
	fseek(data_file, 0, SEEK_SET);			//��������� ��������� �� ������ �����.
	
	int number = 0;
	int first_element;

	if (!fscanf(data_file, "%d", &first_element))	//���������� � ������ ������� �������� ����� + ��������.
	{
		perror("������!");
		return EXIT_FAILURE;
	}
	
	printf("������� ����� ������ ");
	scanf_s("%d", &number);
	
	if (number > first_element)			//��������: ���������� �� ������ � ������ ������� (�.�. ������ ������� - ���������� ����� � ��������).
	{
		printf("�������� ����� ������\n");
		return EXIT_FAILURE;
	}
	
	char ptr, str[50];
	int counter = 0;
	
	for (int i = 0; i < fsize; i++)
	{
		fread(&ptr, sizeof(char), 1, data_file);
		if (ptr == '\n')
		{
			counter++;
		}
		if (counter == (number-1))
		{
			fgets(str, 50, data_file);
			fputs(str, result_file);
			break;
		}
	}

	printf("��������� ������� � ���� resultex1.txt\n");

	fclose(data_file);
	fclose(result_file);
}