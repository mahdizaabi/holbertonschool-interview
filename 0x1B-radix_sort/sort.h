#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
int get_digit(int number, int n);
int getLength(int number);
#endif /* SORT_H */
