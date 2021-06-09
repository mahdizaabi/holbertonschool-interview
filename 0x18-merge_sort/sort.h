#ifndef __SORT__
#define __SORT__

#include <stddef.h>

/*---------------------STRUCTURES---------------------*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - logical type
 * @FALSE: 0
 * @TRUE: 1
 */
typedef enum bool
{
	FALSE,
	TRUE
} bool;

/*---------------------PROTOTYPES---------------------*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int array[], int begin, int end, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_function(int *array, int begin, int end, size_t size);
void counting_sort(int *array, size_t size);
void swap(int *a, int *b);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node_nx(listint_t **list, listint_t *temp);
void swap_node_pr(listint_t **list, listint_t *temp);
void merge_sort(int *array, size_t size);
int findMax(int array[], size_t size);
void fillZero(int array[], size_t size);
void countOccur(int countArray[], int array[], size_t size);
void assignArray(int array1[], int array2[], size_t size);
#endif
