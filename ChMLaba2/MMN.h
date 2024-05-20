#pragma once

#include "IterSlauSolver.h"

class MMN : public IterSlauSolver
{
public:

	double tau;

	MMN() : IterSlauSolver() { tau = 0; }
	MMN(double a, double b, double c, double d, int n, int m) : IterSlauSolver(a, b, c, d, n, m) { tau = 0; }

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