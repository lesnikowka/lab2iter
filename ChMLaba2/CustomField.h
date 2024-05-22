#pragma once

#include <iostream>

#define kMinSize 4

class CustomField
{
public:
	// если область 5х5, передаем 4 (количество разбиений), после 5х5 идет 9х9
	static bool isSizeCorrect(int fieldSize)
	{
		return fieldSize % kMinSize == 0;
	}

	static bool getMult(int fieldSize)
	{
		return fieldSize / kMinSize;
	}

	// если область 5х5, передаем 4 (количество разбиений), после 5х5 идет 9х9
	static bool isInField(int row, int col, int m, int n)
	{
		int halfM = m / 2;
		int halfHalfM = m / 4;
		int halfN = n / 2;
		int halfHalfN = n / 4;

		return row > 0 && row < halfM && col > 0 && col < n ||
			   col < halfHalfN && col > 0 && row > 0 && row < m||
			   col > halfN && col < halfN + halfHalfN && row > 0 && row < m ||
			   row > halfM + halfHalfM && row < m && col > 0 && col < halfN + halfHalfN;
	}

	// если область 5х5, передаем 4 (количество разбиений), после 5х5 идет 9х9
	static bool isBound(int row, int col, int m, int n)
	{
		int halfM = m / 2;
		int halfHalfM = m / 4;
		int halfN = n / 2;
		int halfHalfN = n / 4;

		return row == 0 ||
			   col == 0 ||
			   (row == halfM || row == halfM + halfHalfM) && col >= halfHalfN && col <= halfN ||
			   (col == halfN || col == halfHalfN) && row <= halfM + halfHalfM && row >= halfM ||
			   row == m && col <= halfN + halfHalfN ||
			   col == n && row <= halfM ||
			   col == halfN + halfHalfN && row >= halfM ||
			   row == halfM && col >= halfN + halfHalfN;  
	}

	static void visualizeField(int m, int n)
	{
		std::cout << "  ";
		for (int i = 0; i <= n; i++)
		{
			std::cout << i;
		}
		std::cout << "\n";
		for (int i = 0; i <= m; i++)
		{
			std::cout << i << " ";
			for (int j = 0; j <= n; j++)
			{
				if(isInField(i, j, m, n))
				{
					std::cout << "*";
				}
				if (isBound(i, j, m, n))
				{
					std::cout << "@";
				}
				if (!isInField(i, j, m, n) && !isBound(i, j, m, n))
				{
					std::cout << ".";
				}
			}
			std::cout << "\n";
		}
	}
};