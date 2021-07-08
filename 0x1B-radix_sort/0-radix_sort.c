#include <stdlib.h>
#include "sort.h"

/**
 * get_digit - Returns the numbers of digits of a number.
 * @number:integer
 * @n: interger
 * Return: integer, number of digits
 */
int get_digit(int number, int n)
{
if (n == 0)
{
return (number % 10);
}
int r = 10;
for (int x = 0; x < n - 1; x++)
{
r = r *r;
}
return (number / r % 10);
}
/**
 * getLength - Returns the numbers of digits of a number.
 * @number: interger
 * Return: integer, number of digits
 */

int getLength(int number)
{
int count = 0;
while (number != 0)
{
number /= 10;
++count;
}
return (count);
}
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
 * radix_sort - Sorts an array of ints in ascending order using the radix sort.
 *
 * @array: the array to sort.
 * @size: the size of the array.
 */
void radix_sort(int *array, size_t size)
{

if (array == NULL || size < 2)
return;


int *sortedArray = NULL;
int k = 0;
int flag = 0;

for (int pos = 0; pos < getLength(get_max(array, size)) + 1; pos++)
{
k = 0;
if (flag != 0)
{
for (int j = 0; j < (int)size; j++)
{
array[j] = sortedArray[j];
}
print_array(array, size);
free(sortedArray);
sortedArray = NULL;
}
sortedArray = malloc(sizeof(int) * size);
if (sortedArray == NULL)
return;

for (int rindex = 0; rindex < 10; rindex++)
{
for (int aindex = 0; aindex < (int)size; aindex++)
{
if (get_digit(array[aindex], pos) == rindex)
{
sortedArray[k] = array[aindex];
k++;
}
flag = 1;
}
}
}
}
