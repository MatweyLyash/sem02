#include <iostream>
#include <stdio.h> 

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	FILE* fileA, * fileB;
	
	fopen_s(&fileA, "data_fileEx4.txt", "r");
	fopen_s(&fileB, "result_fileEx4.txt", "w");
	
	if (fileB == NULL || fileA == NULL)
	{
		printf("������ �������� ������ �� ������\n");
		return EXIT_FAILURE;
	}
	else 
	{
		while (!feof(fileA))
		{
			fscanf_s(fileA, "%d", &a);

			if (a > 0)
			{
				fprintf(fileB, "%d ", a);
			}
		}
		printf("���� result_fileEx4.txt ������\n");
		fclose(fileB);
		fclose(fileA);
	}
}