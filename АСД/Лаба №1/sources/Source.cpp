#include <iostream>
#include <chrono>

using namespace std;

auto startFunction = chrono::high_resolution_clock::now();
int Fibonacci(int size)
{
	if (size == 0)
	{
		return 0;
	}
	if (size == 1)
	{
		return 1;
	}
	return Fibonacci(size - 1) + Fibonacci(size - 2);
}
auto endFunction = chrono::high_resolution_clock::now();

int main()
{
	setlocale(LC_ALL, "Rus");
	
	cout << "������� N: ";
	
	int size, first = 0, second = 1, search = 0;
	cin >> size;

	auto startCycle = chrono::high_resolution_clock::now();
	for (int i = 2; i <= size; i++)
	{
		search = first + second;
		first = second;
		second = search;
	}
	auto endCycle = chrono::high_resolution_clock::now();

	chrono::duration<double> durationCycle = endCycle - startCycle;
	chrono::duration<double> durationFunction = endFunction - startFunction;

	cout << "N-� ����� ���������\n����: " << search<<"\t\t����� ����������: "<< durationCycle.count() << "s.ms" <<
		"\n��������: " << Fibonacci(size) << "\t\t����� ����������: " << durationFunction.count() << "s.ms" << endl;

}