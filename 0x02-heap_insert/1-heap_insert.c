#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * swapNode - swap Node.
 * @myNode: pointer to the first node of the list
 * Return: void
 */
void swapNode(heap_t **myNode)
{
	heap_t *move;
	int tmp;

	for (move = *myNode; move->parent; move = move->parent)
		if (move->n > move->parent->n)
		{
			tmp = move->parent->n;
			move->parent->n = move->n;
			move->n = tmp;
			*myNode = (*myNode)->parent;
		}
}
/**
 * enqueue - push inside the Queue
 * @node: pointer to the node to be pushed
 * Return: Void.
 */
void enqueue(heap_t *node)
{

	if (queue.front == -1 && queue.reer == -1)
	{
		queue.front = 0;
		queue.reer = 0;
		queue.array[queue.reer] = node;
	}
	else
	{
		queue.reer = queue.reer + 1;
		queue.array[queue.reer] = node;
	}
}

/**
 * dequeue - pop out from the queue .
 * Return: Void.
 */
void dequeue(void)
{
	if (queue.front == -1 && queue.reer == -1)
		return;
	else if (queue.front == queue.reer)
	{
		queue.front = -1;
		queue.reer = -1;
	}
	else
	{
		queue.front++;
	}
}

/**
 * testx - find the parent node where to insert.
 * @root: root of the tree
 * Return: Pointer to the parent node.
 */
heap_t *testx(heap_t **root)
{

	heap_t *node = NULL;

	queue.front = -1;
	queue.reer = -1;


	enqueue(*root);
	while (2021)
	{
		node = queue.array[queue.front];
		dequeue();
		if (!node->left)
		{
			queue.front = -1;
			queue.reer = -1;
			queue.flag = 1;
			return (node);
		}
		else if (!node->right)
		{

			queue.front = -1;
			queue.reer = -1;
			queue.flag = 2;
			return (node);
		}
		else
		{
			enqueue(node->left);
			enqueue(node->right);
		}
	}
	return (node);
}
/**
 * heap_insert - Max HEAP insertion function.
 * @root: pointer to the first node of the tree
 * @value: number to be inserted
 * Return: Pointer to the new created node.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode = NULL;
	heap_t *parentNode = NULL;

	if (*root == NULL)
	{
	*root = malloc(sizeof(heap_t));
	(*root)->n = value;
	return (*root);
	}

	parentNode = testx(root);

	newNode = malloc(sizeof(heap_t));
	if (newNode == NULL)
		return (NULL);
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->n = value;
	newNode->parent = parentNode;
	if (queue.flag == 1)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;

	if (newNode->n > parentNode->n)
	{
		swapNode(&newNode);
	}

	return (newNode);
}

