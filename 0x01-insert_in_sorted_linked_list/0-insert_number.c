#include "lists.h"

/**
 * insert_node - insert a node in a sorted linked list.
 * @head: pointer to the first node of the list
 * @number: number to be inserter
 * Return: Pointer to the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *pointer = NULL;
	listint_t *newnode = NULL;

	if (*head == NULL)
		return (add_nodeint_end(head, number));

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = number;

	if ((*head)->n > number)
	{
	newnode->next = *head;
	*head = newnode;
	return (newnode);
	}

	else if ((*head)->n < number)
	{
		if ((*head)->next == NULL)
			return (add_nodeint_end(head, number));
		pointer = *head;
	while (pointer->next != NULL)
	{
		if (pointer->next->n > number)
			{
			newnode->next = pointer->next;
			pointer->next = newnode;
			return (newnode);
			}
		pointer = pointer->next;
	}}
	return (add_nodeint_end(head, number));

}
