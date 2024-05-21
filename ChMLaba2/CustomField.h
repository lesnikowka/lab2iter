#pragma once

#include <iostream>

#define kMinSize 4

class CustomField
{
public:
	// ���� ������� 5�5, �������� 4 (���������� ���������), ����� 5�5 ���� 9�9
	static bool isSizeCorrect(int fieldSize)
	{
		return fieldSize % kMinSize == 0;
	}

	static bool getMult(int fieldSize)
	{
		return fieldSize / kMinSize;
	}

	// ���� ������� 5�5, �������� 4 (���������� ���������), ����� 5�5 ���� 9�9
	static bool isInField(int row, int col, int fieldSize)
	{
		int half = fieldSize / 2;
		int halfHalf = fieldSize / 4;

		return row < half ||
			   col < halfHalf ||
			   col > half && col < half + halfHalf ||
			   row > half + halfHalf;
	}

	// ���� ������� 5�5, �������� 4 (���������� ���������), ����� 5�5 ���� 9�9
	static bool isBound(int row, int col, int fieldSize)
	{
		int half = fieldSize / 2;
		int halfHalf = fieldSize / 4;

		return row == 0 ||
			   col == 0 ||
			   (row == half || row == half + halfHalf) && col >= halfHalf && col <= half ||
			   (col == half || col == halfHalf) && row <= half + halfHalf && row >= half ||
			   row == fieldSize && col <= half + halfHalf ||
			   col == fieldSize && row <= half ||
			   col == half + halfHalf && row >= half ||
			   row == half && col >= half + halfHalf;  
	}

	static void visualizeField(int n)
	{
		std::cout << "  ";
		for (int i = 0; i <= n; i++)
		{
			std::cout << i;
		}
		std::cout << "\n";
		for (int i = 0; i <= n; i++)
		{
			std::cout << i << " ";
			for (int j = 0; j <= n; j++)
			{
				if (isBound(i, j, n))
				{
					std::cout << "@";
				}
				else if(isInField(i, j, n))
				{
					std::cout << "*";
				}
				else
				{
					std::cout << ".";
				}
			}
			std::cout << "\n";
		}
	}
};