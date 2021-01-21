#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome - check is a singly list is a palindrome .
 * @head: head of the list .
 * Return: 1 ? palindrome : 0.
 */
int is_palindrome(listint_t **head)
{


	listint_t *counter = NULL;
	int count = 0;
	int stack[1024];
	int endStack = 0;
	int frontStack = 0;
	int r = 0;

	if (*head == NULL)
		return (1);

	counter = *head;

	while (counter)
	{
		count = count + 1;
		stack[endStack] = counter->n;
		endStack++;
		counter = counter->next;
	}
	endStack--;
	r = endStack / 2 + 1;
	while (endStack >= r)
	{
		if (stack[frontStack] != stack[endStack])
			return (0);
		frontStack++;
		endStack--;
	}
	return (1);
}
