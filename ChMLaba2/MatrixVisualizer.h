#pragma once
#include "CustomField.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <map>

int minLength = 4;
int m = 8;
int n = 8;
int numEl = 32;

std::string out;

void coutWithLength(std::string s)
{
	while (s.size() < 5)
	{
		s += " ";
	}
	std::cout << s;
}

std::map<std::pair<int, int>, int> indexes;

void saveIndexes()
{
	//int fake;
	//std::cin >> fake;


	int index = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (CustomField::isInField(i, j, m, n)) 
			{
				indexes.insert({ std::make_pair(i, j), index });

				index++;
			}
		}
	}
}

int getIndex(int i, int j)
{
	return indexes[std::make_pair(i, j)];
}

void visualizeMatrix()
{
	int nnnn;
	std::cin >> nnnn;

	saveIndexes();

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (CustomField::isInField(i, j, m, n))
			{
				std::string right = "-f" + std::to_string(j) + std::to_string(i);

				int curPosition = 0;

				if (CustomField::isBound(i - 1, j, m, n))
				{
					right += " - mu" + std::to_string(j) + std::to_string(i - 1) + "/k2";
				}
				else
				{
					int index = getIndex(i - 1, j);
					for (int k = curPosition; k < index; k++)
					{
						curPosition++;
						coutWithLength(" ");
					}
					coutWithLength("1/k2");
					curPosition++;
				}

				if (CustomField::isBound(i, j - 1, m, n))
				{
					right += " - mu" + std::to_string(j - 1) + std::to_string(i) + "/h2";
				}
				else
				{
					int index = getIndex(i, j - 1);
					for (int k = curPosition; k < index; k++)
					{
						curPosition++;
						coutWithLength(" ");
					}
					coutWithLength("1/h2");
					curPosition++;
				}

				coutWithLength("A");
				curPosition++;

				if (CustomField::isBound(i, j + 1, m, n))
				{
					right += " - mu" + std::to_string(j + 1) + std::to_string(i) + "/h2";
				}
				else
				{
					int index = getIndex(i, j + 1);
					for (int k = curPosition; k < index; k++)
					{
						curPosition++;
						coutWithLength(" ");
					}
					coutWithLength("1/h2");
					curPosition++;
				}

				if (CustomField::isBound(i + 1, j, m, n))
				{
					right += " - mu" + std::to_string(j) + std::to_string(i + 1) + "/k2";
				}
				else
				{
					int index = getIndex(i + 1, j);
					for (int k = curPosition; k < index; k++)
					{
						curPosition++;
						coutWithLength(" ");
					}
					coutWithLength("1/k2");
					curPosition++;
				}

				while (curPosition < numEl)
				{
					curPosition++;
					coutWithLength(" ");
				}

				std::cout << right; 
				std::cout << std::endl;
			}
		}
		//std::cout << std::endl;
	}
}