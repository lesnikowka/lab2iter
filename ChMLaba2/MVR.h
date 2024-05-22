#pragma once

#include "IterSlauSolver.h"

class MVR_Met : public IterSlauSolver
{
public:

	double w;

	MVR_Met() : IterSlauSolver() 
	{
		w = 1.2;
	}

	MVR_Met(double a, double b, double c, double d, int n, int m, double omega = 1.2) : IterSlauSolver(a, b, c, d, n, m) 
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

				if  (abs(vold - vnew) >= acc)
				{
					acc = abs(vold - vnew);
				}

				v[i][j] = vnew;
			}
		}

		return acc;
	}
};
