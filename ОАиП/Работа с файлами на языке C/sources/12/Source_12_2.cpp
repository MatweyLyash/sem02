//������ �������.
#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "rus");

	FILE* nameA_file, * nameB_file, * nameC_file, * nameD_file;

	fopen_s(&nameA_file, "nameA.txt", "r");
	fopen_s(&nameB_file, "nameB.txt", "r");
	fopen_s(&nameC_file, "nameC.txt", "r");
	fopen_s(&nameD_file, "nameD.txt", "w");

	if (nameA_file == NULL || nameB_file == NULL || nameC_file == NULL || nameD_file == NULL)
	{
		perror("������ �������� ������\n");
		return EXIT_FAILURE;
	}
	else
	{
		printf("����� �������\n");
	}

	fseek(nameA_file, 0, SEEK_END);			//����������� ������� ����������� ����� � ������� �������� ��������� � ����� �����.
	long fsize = ftell(nameA_file);
	fseek(nameA_file, 0, SEEK_SET);			//��������� ��������� �� ������ �����.

	int numA, numB, numC;

	while (!feof(nameA_file))				//���� �� ��������� ����� ����� (������ ������ �������� �� �������).
	{
		if (!fscanf(nameA_file, "%d", &numA))	//���������� � ������ �������� ����� + ��������.
		{
			perror("������!");
			return EXIT_FAILURE;
		}
		if (!fscanf(nameB_file, "%d", &numB))
		{
			perror("������!");
			return EXIT_FAILURE;
		}
		if (!fscanf(nameC_file, "%d", &numC))
		{
			perror("������!");
			return EXIT_FAILURE;
		}
		
		if (numA < numB && numA < numC)
		{
			fprintf(nameD_file, "%d ", numA);
		}
		else if (numB < numA && numB < numC)
		{
			fprintf(nameD_file, "%d ", numB);
		}
		else if (numC < numA && numC < numB)
		{
			fprintf(nameD_file, "%d ", numC);
		}
		else
		{
			perror("���������� ��������� ����������� ���������!");
			return EXIT_FAILURE;
		}
	}

	printf("��������� ������� � ���� nameD.txt\n");

	fclose(nameA_file);
	fclose(nameB_file);
	fclose(nameC_file);
	fclose(nameD_file);
}