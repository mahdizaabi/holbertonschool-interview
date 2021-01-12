#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"


/**
  * print_grid - print the grid
  * @grid: grid to print
  * Return: void
  */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
  * checkForUnstable - check for intability
  * @arr: matrix
  * Return: integer
  */


int checkForUnstable(int arr[3][3])
{
	int x;
	int y;

	for (x = 0; x < 3; x++)
	{
		for(y = 0; y < 3; y++)
		{
			if (arr[x][y] > 3)
				return 1;
		}
	}
	return 0;
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
	int a;
	int b;

	for (a = 0; a < 3; a++)
		for(b = 0; b < 3; b++)
			grid1[a][b] = grid1[a][b] + grid2[a][b];
	print_grid(grid1);
	while(2021)
	{
		if (checkForUnstable(grid1) == 0)
			break;
		for(x = 0; x < 3; x++)
			for(y = 0; y < 3; y++)
			{
				if (grid1[x][y] > 3)
				{
					grid1[x][y] = grid1[x][y] - 4;
					if (x - 1 >= 0)
                    				grid1[x - 1][y]++;
                			if (x + 1 <= 2)
                    				grid1[x + 1][y]++;
                			if (y - 1 >= 0)
                    				grid1[x][y - 1]++;
                			if (y + 1 <= 2)
                    				grid1[x][y + 1]++;
				}
			}

		printf("=\n");
    		print_grid(grid1);
		}
}

