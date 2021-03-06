// Lab5_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef double(*quad_func_t)(double);
double trapez(double, double, double, quad_func_t);
double f(double);
double res();

int main()
{
	SetConsoleOutputCP(1251);
	double a = 0, b = 1, eps = 1e-5, S;
	S = trapez(a, b, eps, f);
	double I = res();
	printf("Вычисленно интеграл:\nI=%.5f\nСравниваемый результат\nI=%.5f\n", S, I);
	system("pause");
	return 0;
}

double trapez(double a, double b, double eps, quad_func_t f)
{
	double S = 0, x, h = 0.01;
	x = a;
	while (x < b)
	{
		S = S + (f(x + h) + f(x))*h / 2;
		if (0.5*(f(x + h) + f(x))*h >= eps)
			x = x + h;
		else
			break;

	}
	return S;
}

double f(double x)
{
	return log(x+1)/pow((x+1), 2);
}

double res()
{
	return (1-log(2))/2;
}