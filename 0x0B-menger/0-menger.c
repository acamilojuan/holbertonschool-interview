#include "menger.h"

/**
 * find_char - Find the specific var for a position
 * @column: Column
 * @row: Row
 * Return: ' ' or '#'
 */
char find_char(int column, int row)
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
			printf("%c", find_char(column, row));
		printf("\n");
	}
}
