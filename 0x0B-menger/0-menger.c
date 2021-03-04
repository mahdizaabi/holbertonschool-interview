#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
 * checkForBlank - Checks if indices are (1, 1), if so, then square is blank
 *
 * @i: Row Index
 * @j: Column Index
 *
 * Return: 1 if (1, 1), 0 otherwise
 */

int checkForBlank(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);

		i /= 3, j /= 3;
	}
	return (1);
}

/**
 * menger - function to deaw 2D Menger Sponge
 *
 * @level: level of the spenge
 *
 * Return: Nothing
 */
void menger(int level)
{
	int index, j, max;

	if (level < 0)
		return;

	for (index = 0, max = pow(3, level); index < max; index++)
	{
		for (j = 0; j < max; j++)
			checkForBlank(index, j) == 1 ? printf("%c", '#') : printf("%c", ' ');

		printf("\n");
	}
}
