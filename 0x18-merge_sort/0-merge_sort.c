#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merging_status - track merging from sublist to array
 * @s: start
 * @m: middel
 * @e: end
 * @unmerged: sublist of the array to be merged
 *
 * Return: void
 */

void merging_status(size_t s, size_t m, size_t e, int *unmerged)
{

	printf("Merging...\n");
	printf("[left]: ");
	print_array(unmerged + s, m - s);
	printf("[right]: ");
	print_array(unmerged + m, e - m);
}

/**
 * merge - merge the sublist into the list
 * @start: the start index of the sublist
 * @middle: divide the sublist array into subarrays(left and right)
 * @end: end index of the the sublist to be merged
 * @a: array to be sorted
 * @unmerged: splices/sublist of the array that merge into the array
 *
 * Return: void
 */
void merge(size_t start, size_t middle, size_t end, int *a, int *unmerged)
{
	size_t i = start;
	size_t j = middle;
	size_t k = start;

	merging_status(start, middle, end, unmerged);

	while (i < middle && j < end && k < end)
	{
		if (unmerged[i] <= unmerged[j])
		{
			a[k] = unmerged[i];
			i++;
		}
		else
		{
			a[k] = unmerged[j];
			j++;
		}
		k++;
	}
		while (i < middle)
			a[k++] = unmerged[i++];

		while (j < end)
			a[k++] = unmerged[j++];
}

/**
 * split_merge - split array recursively and merge them back
 * @start: start
 * @end: end
 * @array: the array to sort
 * @unmerged: sublist to be merged
 *
 * Return: void
 */

void split_merge(size_t start, size_t end, int *array, int *unmerged)
{
	size_t count;
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	split_merge(start, middle, array, unmerged);
	split_merge(middle, end, array, unmerged);
	merge(start, middle, end, array, unmerged);
	for (count = start; count < end; count++)
		unmerged[count] = array[count];
	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * @array: array
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *unmerged;

	if (array == NULL || size < 2)
		return;
	unmerged = malloc(sizeof(int) * size);
	if (unmerged == NULL)
		return;
	for (i = 0; i < size; i++)
		unmerged[i] = array[i];
	split_merge(0, size, array, unmerged);
	free(unmerged);
}

