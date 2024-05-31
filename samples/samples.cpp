#include "../ChMLaba2/MMN.h"
#include "../ChMLaba2/MVR.h"
#include "../ChMLaba2/MSG.h"
#include "../ChMLaba2/MSG_UN.h"
#include "../ChMLaba2/Functions.h"

void main()
{
	CustomField::visualizeField(8,8);

	//double Eps = 1e-10;
	//int N = 20000;
	//double a = 0;
	//double b = 1;
	//double c = 0;
	//double d = 2;
	//int n = 120;
	//int m = 120;
	//double w = 1.2;
	//
	//double (*pt1)(double, double) = NULL;
	//double (*pt2)(double, double) = NULL;
	//double (*pt3)(double, double) = NULL;
	//double (*pt4)(double, double) = NULL;
	//double (*ptRight)(double, double) = NULL;
	//
	//pt1 = &boundFunc1Test;
	//pt2 = &boundFunc2Test;
	//pt3 = &boundFunc3Test;
	//pt4 = &boundFunc4Test;
	//ptRight = &rightFuncTest;
	//
	//// MVR тестова€ задача
	//MVR_Met test(a, b, c, d, n, m, w);
	//test.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	//test.initRight(ptRight);
	////test.printSolver();
	//int iterCount = test.solve(N, Eps);
	//double acc = test.getAccuracy();
	//cout << '\n' << iterCount <<  " | " << acc << '\n';
	//vector<vector<double>> res = test.getV();
	////test.printV();
	//vector<double> x = test.getX();
	//vector<double> y = test.getY();
	//double max = 0;
	//for (int i = 1; i < y.size() - 1; i++)
	//{
	//	for (int j = 1; j < x.size() - 1; j++)
	//	{
	//		//cout  << testFunc(x[j], y[i]) << " | ";
	//		if (abs(res[i][j] - testFunc(x[j], y[i])) >= max)
	//		{	
	//			max = abs(res[i][j] - testFunc(x[j], y[i]));
	//		}
	//	}
	//	//cout << '\n';
	//}
	//cout << '\n' << max << '\n';

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

	// MMN_Met тестова€ задача
	//MMN_Met mmn(a, b, c, d, n, m);
	//mmn.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	//mmn.initRight(ptRight);
	////mmn.printSolver();
	//iterCount = mmn.solve(N, Eps);
	//acc = mmn.getAccuracy();
	//cout << '\n' << iterCount << " | " << acc << '\n';
	//res = mmn.getV();
	////mmn.printV();
	//x = mmn.getX();
	//y = mmn.getY();
	//max = 0;
	//for (int i = 1; i < y.size() - 1; i++)
	//{
	//	for (int j = 1; j < x.size() - 1; j++)
	//	{
	//		//cout << testFunc(x[j], y[i]) << " | ";
	//		if (abs(res[i][j] - testFunc(x[j], y[i])) >= max)
	//		{
	//			max = abs(res[i][j] - testFunc(x[j], y[i]));
	//		}
	//	}
	//	//cout << '\n';
	//}
	//cout << '\n' << max << '\n';
	//
	//// ѕроверка на двойной сетке
	///*MMN_Met mmn2(a, b, c, d, 2 * n, 2 * m);
	//mmn2.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	//mmn2.initRight(ptRight);
	//int iterCount2 = mmn2.solve(N * 2, Eps * 1e-2);
	//double acc2 = mmn2.getAccuracy();
	//cout << '\n' << iterCount2 << " | " << acc2 << '\n';
	//vector<vector<double>>res2 = mmn2.getV();
	//vector<double> y2 = mmn2.getY();
	//vector<double> x2 = mmn2.getX();*/
	//
	//// MSG_Met_Met тестова€ задача
	//MSG_Met msg(a, b, c, d, n, m);
	//msg.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	//msg.initRight(ptRight);
	////mmn.printSolver();
	//msg.firstStep();
	//iterCount = msg.solve(N, Eps);
	//acc = msg.getAccuracy();
	//cout << '\n' << iterCount << " | " << acc << '\n';
	//res = msg.getV();
	////msg.printV();
	//x = msg.getX();
	//y = msg.getY();
	//max = 0;
	//for (int i = 1; i < y.size() - 1; i++)
	//{
	//	for (int j = 1; j < x.size() - 1; j++)
	//	{
	//		//cout << testFunc(x[j], y[i]) << " | ";
	//		if (abs(res[i][j] - testFunc(x[j], y[i])) >= max)
	//		{
	//			max = abs(res[i][j] - testFunc(x[j], y[i]));
	//		}
	//	}
	//	//cout << '\n';
	//}
	//cout << '\n' << max << '\n';
	//
	// ѕроверка на двойной сетке
	/*MMN_Met mmn2(a, b, c, d, 2 * n, 2 * m);
	mmn2.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	mmn2.initRight(ptRight);
	int iterCount2 = mmn2.solve(N * 2, Eps * 1e-2);
	double acc2 = mmn2.getAccuracy();
	cout << '\n' << iterCount2 << " | " << acc2 << '\n';
	vector<vector<double>>res2 = mmn2.getV();
	vector<double> y2 = mmn2.getY();
	vector<double> x2 = mmn2.getX();*/
}