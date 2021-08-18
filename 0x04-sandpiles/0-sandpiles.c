#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int a;
	int b;

	for (a = 0; a < len; a++)
	{
		for (b = 0; b < len; b++)
			grid1[a][b] += grid2[a][b];
	}

	while (stabilizer(grid1, grid2))
	{
		printf("=\n");
		a = 0;
		while (a < len)
		{
			for (b = 0; b < len; b++)
				printf((b == len - 1) ? "%d\n" : "%d ", grid1[a][b]);
			a++;
		}
		for (a = 0; a < len; a++)
		{
			for (b = 0; b < len; b++)
			{
				if (grid2[a][b] > 3)
				{
					grid1[a][b] -= 4;
					if (a > 0)
						++grid1[a - 1][b];
					if (a < len - 1)
						++grid1[a + 1][b];
					if (b > 0)
						++grid1[a][b - 1];
					if (b < len - 1)
						++grid1[a][b + 1];
				}
			}
		}
	}
}

/**
 * stabilizer - Verify the stability of the sandpile
 * @grid: The sandpile
 * @copy: copy of sandpile to be analized
 * Return: 1 if unstable 0 if stable
 */
int stabilizer(int grid[3][3], int copy[3][3])
{
	int a = 0;
	int b;
	int stabillity = 0;

	while (a < len)
	{
		for (b = 0; b < len; b++)
		{
			copy[a][b] = grid[a][b];
			if (copy[a][b] > 3)
				stabillity = 1;
		}
		a++;
	}

	return (stabillity);
}
