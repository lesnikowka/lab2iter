#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Windows.h>

#include "CustomField.h"

using namespace std;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::IO;

int progressMethod = 0;

template<typename T>
double scalarMult(vector<T> r, vector<T> l)
{
	double res = 0;
	if (r.size() != l.size())
	{
		return res;
	}

	for (int i = 0; i < r.size(); i++)
	{
		res += r[i] * l[i];
	}
	return res;
}

class IterSlauSolver
{
public:
	double h;
	double k;
	double kcoef;
	double hcoef;
	double acoef;
	double accuracy;
	int nX; //Количесвто промежутков по х
	int mY; //Количесвто промежутков по y
	vector<vector<double>> right;
	vector<vector<double>> v;
	vector<vector<double>> r;
	vector<double> xArr;
	vector<double> yArr;
	vector<double> bound1;
	vector<double> bound2;
	vector<double> bound3;
	vector<double> bound4;

	IterSlauSolver()
	{
		k = 0;
		h = 0;
		kcoef = 0;
		hcoef = 0;
		acoef = 0;
		accuracy = 0;
		nX = 0; //Количество  разбиений по x
		mY = 0; //Количество  разбиений по y
		yArr.push_back(0);
		xArr.push_back(0);
		right.push_back(vector<double>());
		v.push_back(vector<double>());
		r.push_back(vector<double>());
	}

	IterSlauSolver(double a, double b, double c, double d, int n, int m)
	{
		nX = n;
		mY = m;
		h = (b - a) / n;
		k = (d - c) / m;
		hcoef = 1 / (h * h);
		kcoef = 1 / (k * k);
		acoef = -2 * (kcoef + hcoef);
		accuracy = 0;

		for (int i = 0; i < m + 1; i++)
		{
			yArr.push_back(c);
			c += k;
			v.push_back(vector<double>(n + 1));
			r.push_back(vector<double>(n + 1));
			right.push_back(vector<double>(n + 1));
		}

		for (int i = 0; i < n + 1; i++)
		{
			xArr.push_back(a);
			a += h;
		}
	}

	void initBounds(double (*ptFunc1)(double, double), double (*ptFunc2)(double, double), double (*ptFunc3)(double, double), double (*ptFunc4)(double, double), double a, double b, double c, double d)
	{
		for (int i = 0; i < xArr.size(); i++)
		{
			bound1.push_back((*ptFunc1)(xArr[i], c));
			v[0][i] = ((*ptFunc1)(xArr[i], c));
			bound2.push_back((*ptFunc2)(xArr[i], d));
			v[mY][i] = ((*ptFunc2)(xArr[i], d));
		}
		for (int i = 0; i < yArr.size(); i++)
		{
			bound3.push_back((*ptFunc3)(a, yArr[i]));
			v[i][0] = ((*ptFunc3)(a, yArr[i]));
			bound4.push_back((*ptFunc4)(b, yArr[i]));
			v[i][nX] = ((*ptFunc4)(b, yArr[i]));
		}
	}

	void initBoundSpec(double (*ptFunc)(double, double))
	{
		for (int i = 0; i < yArr.size(); i++)
		{
			for (int j = 0; i < xArr.size(); j++)
			{
				if (CustomField::isBound(i, j, mY, nX))
				{
					v[i][j] = ((*ptFunc)(xArr[j], yArr[i]));
				}
			}
		}
	}

	void initRight(double (*ptFucn)(double, double))
	{
		for (int i = 1; i < yArr.size() - 1; i++)
		{
			for (int j = 1; j < xArr.size() - 1; j++)
			{
				right[i][j] = -((*ptFucn)(xArr[j], yArr[i]));
				if (i == 1 && j == 1)
				{
					right[i][j] -= hcoef * bound3[i] + kcoef * bound1[j];
				}
				else if (i == 1 && j == nX - 1)
				{
					right[i][j] -= hcoef * bound4[i] + kcoef * bound1[j];
				}
				else if (i == 1)
				{
					right[i][j] -= kcoef * bound1[j];
				}
				else if (i == mY - 1 && j == 1)
				{
					right[i][j] -= hcoef * bound3[i] + kcoef * bound2[j];
				}
				else if (i == mY - 1 && j == nX - 1)
				{
					right[i][j] -= hcoef * bound4[i] + kcoef * bound2[j];
				}
				else if (i == mY - 1)
				{
					right[i][j] -= kcoef * bound2[j];
				}
				else if (j == 1)
				{
					right[i][j] -= hcoef * bound3[i];
				}
				else if (j == nX - 1)
				{
					right[i][j] -= hcoef * bound4[i];
				}
			}
		}
	}

	void initB(vector<double> b)
	{
		for (int i = 1; i < right.size() - 1; i++)
		{
			for (int j = 1; j < right[i].size() - 1; j++)
			{
				right[i][j] = b[(i - 1) * nX + (j - 1)];
			}
		}
	}

	void initA(double ac, double kc, double hc)
	{
		acoef = ac;
		kcoef = kc;
		hcoef = hc;
	}

	void printV()
	{
		cout << "\nv: \n";
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				cout << v[i][j] << " | ";
			}
			cout << '\n';
		}
		cout << '\n';
	}

	void printRight()
	{
		cout << "\nb: \n";
		for (int i = 0; i < right.size(); i++)
		{
			for (int j = 0; j < right[i].size(); j++)
			{
				cout << right[i][j] << " | ";
			}
			cout << '\n';
		}
		cout << '\n';
	}

	void printSolver()
	{
		cout << "\nh: " << h << " k: " << k << '\n';
		cout << "hcoef: " << hcoef << " kcoef: " << kcoef << " acoef: " << acoef << '\n' << '\n';
		printV();
		printRight();
	}

	void printXandY()
	{
		cout << xArr.size() << '\n';
		for (int i = 0; i < xArr.size(); i++)
		{
			cout << xArr[i] << " | ";
		}
		cout << '\n' << yArr.size() << '\n';
		for (int i = 0; i < yArr.size(); i++)
		{
			cout << yArr[i] << " | ";
		}
		cout << '\n';
	}

	vector<double> getX()
	{
		return xArr;
	}

	vector<double> getY()
	{
		return yArr;
	}

	vector<vector<double>> getV()
	{
		return v;
	}

	double getAccuracy()
	{
		return accuracy;
	}

	void calculateR()
	{
		for (int i = 1; i < v.size() - 1; i++)
		{
			for (int j = 1; j < v[i].size() - 1; j++)
			{
				r[i][j] = (hcoef * (v[i][j + 1] + v[i][j - 1]) + kcoef * (v[i - 1][j] + v[i + 1][j]) + acoef * v[i][j]) - right[i][j];
			}
		}
	}

	virtual double step(bool flag = false) { cout << 0;  return 0; }

	double calcNorm2R()
	{
		double res = 0;
		for (int i = 1; i < v.size() - 1; i++)
		{
			for (int j = 1; j < v[i].size() - 1; j++)
			{
				res += r[i][j] * r[i][j];
			}
		}
		return sqrt(res);
	}

	//Бесконечности
	double calcNormR()
	{
		double res = 0;
		for (int i = 1; i < v.size() - 1; i++)
		{
			for (int j = 1; j < v[i].size() - 1; j++)
			{
				if (res <= abs(r[i][j]))
				{
					res = abs(r[i][j]);
				}
			}
		}
		return res;
	}

	int solve(int n, double eps, BackgroundWorker^ worker)
	{
		int res = 0;
		for (int iter = 0; iter < n; iter++)
		{
			progressMethod++;
			worker->ReportProgress(1);
			res++;
			accuracy = step();
			if (accuracy < eps)
			{
				return res;
			}
		}
		return res;
	}
};