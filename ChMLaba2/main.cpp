#include "MSG.h"
#include "MVR.h"
#include "MMN.h"
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
	//double d = ;
	//double c = ;
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

void main()
{
	double Eps = 1e-8;
	int N = 20000;
	double a = 0;
	double b = 1;
	double c = 0;
	double d = 2;
	int n = 50;
	int m = 50;
	double w = 1.2;

	double (*pt1)(double, double) = NULL;
	double (*pt2)(double, double) = NULL;
	double (*pt3)(double, double) = NULL;
	double (*pt4)(double, double) = NULL;
	double (*ptRight)(double, double) = NULL;

	pt1 = &boundFunc1Test;
	pt2 = &boundFunc2Test;
	pt3 = &boundFunc3Test;
	pt4 = &boundFunc4Test;
	ptRight = &rightFuncTest;

	// MVR тестова€ задача
	MVR test(a, b, c, d, n, m, w);
	test.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	test.initRight(ptRight);
	//test.printSolver();
	int iterCount = test.solve(N, Eps);
	double acc = test.getAccuracy();
	cout << '\n' << iterCount <<  " | " << acc << '\n';
	vector<vector<double>> res = test.getV();
	//test.printV();
	vector<double> x = test.getX();
	vector<double> y = test.getY();
	double max = 0;
	for (int i = 1; i < y.size() - 1; i++)
	{
		for (int j = 1; j < x.size() - 1; j++)
		{
			//cout  << testFunc(x[j], y[i]) << " | ";
			if (abs(res[i][j] - testFunc(x[j], y[i])) >= max)
			{	
				max = abs(res[i][j] - testFunc(x[j], y[i]));
			}
		}
		//cout << '\n';
	}
	cout << '\n' << max << '\n';

	// ѕроверка на двойной сетке
	/*MVR test2(a, b, c, d, 2 * n, 2 * m, w);
	test2.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	test2.initRight(ptRight);
	int iterCount2 = test2.solve(N * 2, Eps * 1e-2);
	double acc2 = test2.getAccuracy();
	cout << '\n' << iterCount2 << " | " << acc2 << '\n';
	vector<vector<double>>res2 = test2.getV();
	vector<double> y2 = test2.getY();
	vector<double> x2 = test2.getX();*/

	// MMN тестова€ задача
	MMN mmn(a, b, c, d, n, m);
	mmn.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	mmn.initRight(ptRight);
	//mmn.printSolver();
	iterCount = mmn.solve(N, Eps);
	acc = mmn.getAccuracy();
	cout << '\n' << iterCount << " | " << acc << '\n';
	res = mmn.getV();
	//mmn.printV();
	x = mmn.getX();
	y = mmn.getY();
	max = 0;
	for (int i = 1; i < y.size() - 1; i++)
	{
		for (int j = 1; j < x.size() - 1; j++)
		{
			//cout << testFunc(x[j], y[i]) << " | ";
			if (abs(res[i][j] - testFunc(x[j], y[i])) >= max)
			{
				max = abs(res[i][j] - testFunc(x[j], y[i]));
			}
		}
		//cout << '\n';
	}
	cout << '\n' << max << '\n';

	// ѕроверка на двойной сетке
	/*MMN mmn2(a, b, c, d, 2 * n, 2 * m);
	mmn2.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	mmn2.initRight(ptRight);
	int iterCount2 = mmn2.solve(N * 2, Eps * 1e-2);
	double acc2 = mmn2.getAccuracy();
	cout << '\n' << iterCount2 << " | " << acc2 << '\n';
	vector<vector<double>>res2 = mmn2.getV();
	vector<double> y2 = mmn2.getY();
	vector<double> x2 = mmn2.getX();*/

	// MSG тестова€ задача
	MSG msg(a, b, c, d, n, m);
	msg.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	msg.initRight(ptRight);
	//mmn.printSolver();
	msg.firstStep();
	iterCount = msg.solve(N, Eps);
	acc = msg.getAccuracy();
	cout << '\n' << iterCount << " | " << acc << '\n';
	res = msg.getV();
	//msg.printV();
	x = msg.getX();
	y = msg.getY();
	max = 0;
	for (int i = 1; i < y.size() - 1; i++)
	{
		for (int j = 1; j < x.size() - 1; j++)
		{
			//cout << testFunc(x[j], y[i]) << " | ";
			if (abs(res[i][j] - testFunc(x[j], y[i])) >= max)
			{
				max = abs(res[i][j] - testFunc(x[j], y[i]));
			}
		}
		//cout << '\n';
	}
	cout << '\n' << max << '\n';

	// ѕроверка на двойной сетке
	/*MMN mmn2(a, b, c, d, 2 * n, 2 * m);
	mmn2.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	mmn2.initRight(ptRight);
	int iterCount2 = mmn2.solve(N * 2, Eps * 1e-2);
	double acc2 = mmn2.getAccuracy();
	cout << '\n' << iterCount2 << " | " << acc2 << '\n';
	vector<vector<double>>res2 = mmn2.getV();
	vector<double> y2 = mmn2.getY();
	vector<double> x2 = mmn2.getX();*/
}