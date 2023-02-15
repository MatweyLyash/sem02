#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	FILE* fileF, *fileG;
	
	fopen_s(&fileF, "f.txt", "r");
	fopen_s(&fileG, "g.txt", "w");
	
	if (fileF == NULL || fileG == NULL)
	{
		perror("������ �������� ����� f.txt ��� g.txt\n");
		return EXIT_FAILURE;
	}
	else
	{
		printf("����� �������!\n");
	}
	
	printf("������� ����� ��� ���������: ");
	int number;
	scanf_s("%d", &number);

	while (!feof(fileF))
	{
		int numberF;
		fscanf_s(fileF, "%d", &numberF);
		if (numberF > number)
		{
			fprintf(fileG, "%d ", numberF);
		}
	}

	printf("��������� ������� � ���� g.txt\n");
}