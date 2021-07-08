#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the number of digits of the biggest int in the array.
 *
 * @array: array to seach into.
 * @size: size of the array.
 *
 * Return: the biggest element of the array.
 */
int get_max(int *array, int size)
{
	int maxNum, i;

	maxNum = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > maxNum)
			maxNum = array[i];
	}

	return (maxNum);
}

/**
 * count_sort - Sort an array of ints according to their Ith digit.
 *
 * @array: the array to sort.
 * @size: the size of the array.
 * @di: the index of the digit according to which the array will be sorted.
 */
void count_sort(int *array, int size, int di)
{
	int ce, cd, ce2, cd2, tmp, x;

	ce = 0;
	while (ce < size)
	{
		cd = (array[ce] / di) % 10;
		ce2 = ce;
		while (ce2 < size)
		{
			cd2 = (array[ce2] / di) % 10;
			if (cd > cd2)
			{
				tmp = array[ce2];
				for (x = ce2 - 1; x >= ce; x--)
				{
					array[x + 1] = array[x];
				}
				array[ce] = tmp;
				ce = -1;
				break;
			}
			ce2++;
		}
		ce++;
	}
}

/**
 * radix_sort - Sorts an array of ints in ascending order using the radix sort.
 *
 * @array: the array to sort.
 * @size: the size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int s, max, i;

	if (array == NULL || size < 2)
		return;
	s = (int) size;
	max = get_max(array, s);
	i = 1;
	while ((max / i) > 0)
	{
		count_sort(array, s, i);
		print_array(array, size);
		i *= 10;
	}
}