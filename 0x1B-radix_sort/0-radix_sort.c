#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int get_digit(int number, int n)
{
    if (n == 0)
    {
    return number % 10;
    }
    int r = 10;
    for (int x = 0; x < n - 1; x++)
    {
    r = r * r;
    }
return number / r % 10;
}

int getLength(int number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        ++count;
    }
    return count;
}

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

void radix_sort(int *array, size_t size)
{

    int *sortedArray = NULL;
    int k = 0;
    int flag = 0;

    for (int position = 0; position < getLength(get_max(array, size)) + 1; position++)
    {

        k = 0;
        if (flag != 0)
        {
            for (int j = 0; j < 10; j++)
            {
                array[j] = sortedArray[j];
            }
            print_array(array, size);
        }
        sortedArray = NULL;
        sortedArray = malloc(sizeof(int) * size);
        for (int rindex = 0; rindex < (int)size; rindex++)
        {
            for (int aindex = 0; aindex < (int)size; aindex++)
            {
                if (get_digit(array[aindex], position) == rindex)
                {
                    sortedArray[k] = array[aindex];
                    k++;
                }
                flag = 1;
            }
        }
    }
}