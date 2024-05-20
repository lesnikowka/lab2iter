#pragma once

namespace CustomField
{
	const int kMinSize = 4;

	bool isSizeCorrect(int fieldSize)
	{
		return fieldSize % kMinSize == 0;
	}

	bool getMult(int fieldSize)
	{
		return fieldSize / kMinSize;
	}

	bool isInField(int row, int col, int fieldSize)
	{
		return row < fieldSize / 2 ||
			col < fieldSize / 4 ||
			col > fieldSize / 2 && col < fieldSize / 2 + fieldSize / 4 ||
			row > fieldSize / 2 + fieldSize / 4;
	}
}