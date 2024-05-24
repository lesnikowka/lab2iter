#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

# define M_PI           3.14159265358979323846

double rightFuncTest(double x, double y)
{
	double a = exp(sin(M_PI * x * y) * sin(M_PI * x * y)) * 0.5;
	double b = (x * x + y * y);
	double d = M_PI * M_PI;
	double c = (-1 - 4 * cos(2 * M_PI * x * y) + cos(4 * M_PI * x * y));
	return a * b * c * d;
}

double rightFuncTest2(double x, double y)
{
	double a = 2 * M_PI * M_PI * y * y * exp(sin(M_PI * x * y) * sin(M_PI * x * y));
	double b = 2 * sin(M_PI * x * y) * sin(M_PI * x * y) * cos(M_PI * x * y) * cos(M_PI * x * y) - sin(M_PI * x * y) * sin(M_PI * x * y) + cos(M_PI * x * y) * cos(M_PI * x * y);
	return a * b;
}

double boundFunc1Test(double x, double y)
{
	return 1;
}

double boundFunc2Test(double x, double y)
{
	return exp(sin(2 * M_PI * x) * sin(2 * M_PI * x));
}

double boundFunc3Test(double x, double y)
{
	return 1;
}

double boundFunc4Test(double x, double y)
{
	return exp(sin(M_PI * y) * sin(M_PI * y));
}

double testFunc(double x, double y)
{
	return exp(sin(y * M_PI * x) * sin(y * M_PI * x));
}

double boundFunc1Main(double x, double y)
{
	return x * (1 - x);
}

double boundFunc2Main(double x, double y)
{
	return x * (1-x) * exp(x);
}

double boundFunc3Main(double x, double y)
{
	return (sin(M_PI*y)) * (sin(M_PI*y));
}

double boundFunc4Main(double x, double y)
{
	return abs(exp(sin(M_PI * y)) - 1);
}

double rightMain(double x, double y)
{
	return -abs(x - y);
}
