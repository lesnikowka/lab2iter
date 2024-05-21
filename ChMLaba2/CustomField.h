#pragma once

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

	static bool isInField(int row, int col, int fieldSize)
	{
		return row < fieldSize / 2 ||
			col < fieldSize / 4 ||
			col > fieldSize / 2 && col < fieldSize / 2 + fieldSize / 4 ||
			row > fieldSize / 2 + fieldSize / 4;
	}
};