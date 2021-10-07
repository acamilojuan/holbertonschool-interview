#include "menger.h"

/**
 * findch - Fx to find the char
 * @column: Column
 * @row: Row
 * Return: ' ' or '#'
 */
char findch(int column, int row)
{
	for (; column && row; column /= 3, row /= 3)
		if (column % 3 == 1 && row % 3 == 1)
			return (' ');

	return ('#');
}

/**
 * menger - Prints flat menger
 * @level: Level of the Sponge
 */
void menger(int level)
{
	int column;
	int row;
	int size = pow(3, level);

	if (level < 0)
		return;

	for (column = 0; column < size; column++)
	{
		for (row = 0; row < size; row++)
			printf("%c", findch(column, row));
		printf("\n");
	}
}
