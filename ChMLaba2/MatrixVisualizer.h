#pragma once
#include "CustomField.h"
#include <vector>
#include <unordered_map>
#include <string>

int minLength = 5;
int m = 8;
int n = 8;

void coutWithLength(std::string s)
{
	while (s.size() < 5)
	{
		s += " ";
	}
	std::cout << s;
}


void visualizeMatrix()
{
	int curIndex = 0;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (CustomField::isInField(i, j, m, n))
			{
				std::string right = "-f" + std::to_string(j) + std::to_string(i);

				if (CustomField::isBound(i - 1, j, m, n))
				{
					right += " - mu" + std::to_string(j) + std::to_string(i - 1) + "/k2";
				}
				if (CustomField::isBound(i + 1, j, m, n))
				{
					right += " - mu" + std::to_string(j) + std::to_string(i + 1) + "/k2";
				}
				if (CustomField::isBound(i, j - 1, m, n))
				{
					right += " - mu" + std::to_string(j - 1) + std::to_string(i) + "/h2";
				}
				if (CustomField::isBound(i, j + 1, m, n))
				{
					right += " - mu" + std::to_string(j + 1) + std::to_string(i) + "/h2";
				}

				std::cout << right << std::endl;



				curIndex++;
			}
		}
		std::cout << std::endl;
	}
}