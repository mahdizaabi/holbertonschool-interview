#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

#define N 100

heap_t *array[N];
int front = -1;
int reer = -1;

void enqueue(heap_t *node)
{

	if(reer == N - 1)
		printf("overflow");
	if(front == -1 && reer == -1)
	{
		front = reer = 0;
		array[reer] = node;
	}
	else
	{
		reer = reer + 1;
		printf("%d\n", reer);
		printf("%d\n", front);
		array[reer] = node;
	}
}

void dequeue()
{
	if(front == -1 && reer == -1) {
		return;
	}
	else if(front == reer)
	{
		front = reer = -1;
	}
	else
	{
		front++;
	}
}

heap_t *testx(heap_t **root)
{

	heap_t *node = NULL;

	enqueue(*root);
	while(front != -1)
	{
	
		node = array[front];
		printf("%d", node->n);
		dequeue();
		if(!node->left)
		{
			printf("left empty");
			return(node);
		}
		else if (!node->right)
		{
			printf("right empty");
			return(node);
		}
		else
		{
			enqueue(node->left);
			enqueue(node->right);
		}
	}
	return(node);
}

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode;
	heap_t *parentNode;

	if (*root == NULL)
	{
        *root = malloc(sizeof(heap_t));
        (*root)->n = value;
        return (*root);
	}

	parentNode = testx(root);

	newNode = malloc(sizeof(heap_t));
	if(newNode == NULL)
		return NULL;
	newNode->n = value;
	newNode->parent = parentNode;
	if(parentNode->left == NULL)
	{

		parentNode->left = newNode;
	}
	else
	{
		parentNode->right = newNode;

	}
	return(newNode);
}

