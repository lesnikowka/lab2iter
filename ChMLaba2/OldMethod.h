#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Functions.h"
using namespace std;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::IO;


class IterSlauSolverOld
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

	IterSlauSolverOld()
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

	IterSlauSolverOld(double a, double b, double c, double d, int n, int m)
	{
		nX = n;
		mY = m;
		h = (b - a) / n;
		k = (d - c) / m;
		hcoef = 1 / (h * h);
		kcoef = 1 / (k * k);
		acoef = -2 * (kcoef + hcoef);
		accuracy = 0;
		v.clear();
		r.clear();
		yArr.clear();
		xArr.clear();
		right.clear();
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


	~IterSlauSolverOld()
	{
		right.clear();
		v.clear();
		r.clear();
		kcoef = 0;
		hcoef = 0;
		acoef = 0;
		nX = 0;
		mY = 0;
	}

	void initBounds(double (*ptFunc1)(double, double), double (*ptFunc2)(double, double), double (*ptFunc3)(double, double), double (*ptFunc4)(double, double), double a, double b, double c, double d)
	{
		for (int i = 0; i < xArr.size(); i++)
		{
			bound1.push_back((*ptFunc1)(xArr[i], c));
			bound2.push_back((*ptFunc2)(xArr[i], d));
		}
		for (int i = 0; i < yArr.size(); i++)
		{
			bound3.push_back((*ptFunc3)(a, yArr[i]));
			bound4.push_back((*ptFunc4)(b, yArr[i]));
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
		vector<double> res = xArr;
		return res;
	}

	vector<double> getY()
	{
		vector<double> res = yArr;
		return res;
	}

	vector<vector<double>> getV()
	{
		vector<vector<double>> res = v;
		return res;
	}

	double getAccuracy()
	{
		double res = accuracy;
		return res;
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

	virtual double step() { cout << 0;  return 0; }

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


class MMN_old : public IterSlauSolverOld
{
public:

	double tau;

	MMN_old() : IterSlauSolverOld() { tau = 0; }
	MMN_old(double a, double b, double c, double d, int n, int m) : IterSlauSolverOld(a, b, c, d, n, m) { tau = 0; }

	void calculateTau()
	{
		double Arij;
		double ArR = 0;
		double Ar2 = 0;
		for (int i = 1; i < r.size() - 1; i++)
		{
			for (int j = 1; j < r[i].size() - 1; j++)
			{
				Arij = hcoef * (r[i][j + 1] + r[i][j - 1]) + kcoef * (r[i - 1][j] + r[i + 1][j]) + acoef * r[i][j];
				ArR += Arij * r[i][j];
				Ar2 += Arij * Arij;
			}
		}

		tau = ArR / Ar2;
	}

	double step() override//возвращает разность vs - (vs + 1)
	{
		double vij;
		double res = 0;

		calculateR();
		calculateTau();
		for (int i = 1; i < v.size() - 1; i++)
		{
			for (int j = 1; j < v[i].size() - 1; j++)
			{
				vij = v[i][j] - tau * r[i][j];
				v[i][j] = vij;
				if (res <= abs(tau * r[i][j]))
				{
					res = abs(tau * r[i][j]);
				}
			}
		}
		return res;
	}
};


class MVR_old : public IterSlauSolverOld
{
public:

	double w;

	MVR_old() : IterSlauSolverOld()
	{
		w = 1.2;
	}

	MVR_old(double a, double b, double c, double d, int n, int m, double omega = 1.2) : IterSlauSolverOld(a, b, c, d, n, m)
	{
		w = omega;
	}

	double step() override
	{
		double vold;
		double vnew;
		double acc = 0;
		for (int i = 1; i < v.size() - 1; i++)
		{
			for (int j = 1; j < v[i].size() - 1; j++)
			{
				vold = v[i][j];
				vnew = -w * (hcoef * (v[i][j + 1] + v[i][j - 1]) + kcoef * (v[i + 1][j] + v[i - 1][j]));
				vnew += (1 - w) * acoef * v[i][j] + w * right[i][j];
				vnew /= acoef;
				if (abs(vold - vnew) >= acc);
				{
					acc = abs(vold - vnew);
				}
				v[i][j] = vnew;
			}
		}
		return acc;
	}
};


class MSG_old : public IterSlauSolverOld
{
public:
	double alpha;
	double betta;
	vector<vector<double>> dir; //это h(s)

	MSG_old() : IterSlauSolverOld()
	{
		alpha = 0;
		betta = 0;
		dir.push_back(vector<double>());
	}

	MSG_old(double a, double b, double c, double d, int n, int m) : IterSlauSolverOld(a, b, c, d, n, m)
	{
		alpha = 0;
		betta = 0;
		dir.clear();
		for (int i = 0; i < m + 1; i++)
		{
			dir.push_back(vector<double>(n + 1));
		}
	}

	void calcDir()
	{
		for (int i = 1; i < dir.size() - 1; i++)
		{
			for (int j = 1; j < dir[i].size() - 1; j++)
			{
				dir[i][j] = -r[i][j] + betta * dir[i][j];
			}
		}
	}

	void calcAlpha()
	{
		double Ahij;
		double AhR = 0;
		double Ah2 = 0;
		for (int i = 1; i < dir.size() - 1; i++)
		{
			for (int j = 1; j < dir[i].size() - 1; j++)
			{
				Ahij = hcoef * (dir[i][j + 1] + dir[i][j - 1]) + kcoef * (dir[i - 1][j] + dir[i + 1][j]) + acoef * dir[i][j];
				AhR += dir[i][j] * r[i][j];
				Ah2 += Ahij * dir[i][j];
			}
		}
		alpha = -(AhR / Ah2);
	}

	void calcBetta()
	{
		double Ahij;
		double AhR = 0;
		double Ah2 = 0;
		for (int i = 1; i < dir.size() - 1; i++)
		{
			for (int j = 1; j < dir[i].size() - 1; j++)
			{
				Ahij = hcoef * (dir[i][j + 1] + dir[i][j - 1]) + kcoef * (dir[i - 1][j] + dir[i + 1][j]) + acoef * dir[i][j];
				AhR += Ahij * r[i][j];
				Ah2 += Ahij * dir[i][j];
			}
		}

		betta = AhR / Ah2;
	}

	double firstStep()
	{
		double res = 0;
		calculateR();
		calcDir();
		calcAlpha();
		for (int i = 1; i < v.size() - 1; i++)
		{
			for (int j = 1; j < v[i].size() - 1; j++)
			{
				v[i][j] = v[i][j] + alpha * dir[i][j];
				if (abs(alpha * dir[i][j]) >= res)
				{
					res = abs(alpha * dir[i][j]);
				}
			}
		}
		return res;
	}

	double step() override
	{
		double res = 0;
		calculateR();
		calcBetta();
		calcDir();
		calcAlpha();
		for (int i = 1; i < v.size() - 1; i++)
		{
			for (int j = 1; j < v[i].size() - 1; j++)
			{
				v[i][j] = v[i][j] + alpha * dir[i][j];
				if (abs(alpha * dir[i][j]) >= res)
				{
					res = abs(alpha * dir[i][j]);
				}
			}
		}
		return res;
	}

};