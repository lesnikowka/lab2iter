#pragma once

class MSG_Met : public IterSlauSolver
{
public:
	double alpha;
	double betta;
	vector<vector<double>> dir; 

	MSG_Met() : IterSlauSolver()
	{
		alpha = 0;
		betta = 0;
		dir.push_back(vector<double>());
	}

	MSG_Met(double a, double b, double c, double d, int n, int m) : IterSlauSolver(a, b, c, d, n, m)
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

	double step(bool flag = false) override
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