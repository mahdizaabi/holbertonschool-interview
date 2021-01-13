#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"



/**
  * print_grid - Print 3x3 grid
  * @grid: 3x3 grid
  *
  */
static void print_grid(int grid[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
	printf("\n");
	}
}

/**
  * copyReference - check for intability
  * @src: sandpile ti copy
  * @dest: sandpile destination
  * Return: integer
  */

void copyReference(int src[3][3], int dest[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int y = 0; y < 3; y++)
		{
			dest[i][y] = src[i][y];
		}
}
/**
  * checkForUnstable - check for intability
  * @arr: matrix
  * Return: integer
  */
int checkForUnstable(int arr[3][3])
{

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (arr[x][y] > 3)
				return (1);
		}
	}
	return (0);
}


/**
  * sandpiles_sum - Matrix sommation
  * @grid1: matrix to be add
  * @grid2: matrix to be add
  * Return: void
  */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	int x;
	int y;
	int referenceGrid[3][3];

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] = grid1[x][y] + grid2[x][y];

	printf("=\n");
	print_grid(grid1);
	while (checkForUnstable(grid1))
	{

		copyReference(grid1, referenceGrid);
		for (x = 0; x < 3; x++)
			for (y = 0; y < 3; y++)
			{
				if (referenceGrid[x][y] > 3)
				{
					grid1[x][y] = grid1[x][y] - 4;
					if (x - 1 >= 0)
						grid1[x - 1][y] += 1;
					if (x + 1 <= 2)
						grid1[x + 1][y] += 1;
					if (y - 1 >= 0)
						grid1[x][y - 1] += 1;
					if (y + 1 <= 2)
						grid1[x][y + 1] += 1;
				}
			}
		if (!checkForUnstable(grid1))
			break;
		printf("=\n");
		print_grid(grid1);
	}
}
