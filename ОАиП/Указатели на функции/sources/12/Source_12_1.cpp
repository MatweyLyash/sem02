////������ ����� ���� (������� �� ������ �������)
////[0; 3] - ���������� ��� �����.
//#include <iostream>
//
//#define ACCURACY 0.001					//��������
//
//using namespace std;
//
//double equationNum1(double x)			//������ ���������
//{
//	return 2 * x + pow(x, 3) - 7;
//}
//
//double equationNum2(double x)			//������ ���������
//{
//	return exp(x) + 2 * x;
//}
//
//double dichotomy(double a, double b, double(*equation)(double x))
//{
//	double x = 0;
//
//	while (b - a > ACCURACY)
//	{
//		x = (a + b) / 2;
//
//		if ((*equation)(a) * (*equation)(x) < 0)
//		{
//
//			b = x;
//		}
//		else
//		{
//
//			a = x;
//		}
//	}
//	return x;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	double (*ptrEquationNum1)(double x) = &equationNum1;			//��������� �� �������, ���������� ������ ���������
//	double (*ptrEquationNum2)(double x) = &equationNum2;		//��������� �� �������, ���������� ������ ���������
//
//	double a, b;
//
//	cout << "������� ���������� (a,b) ��� ������� ���������: " << endl;
//	cin >> a >> b;
//
//	cout << "������ ������� ���������: " << dichotomy(a, b, ptrEquationNum1) << endl;
//
//	cout << "������� ���������� (a,b) ��� ������� ���������: " << endl;
//	cin >> a >> b;
//
//	cout << "������ ������� ���������: " << dichotomy(a, b, ptrEquationNum2) << endl;
//}