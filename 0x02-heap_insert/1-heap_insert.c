#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


heap_t *heap_insert(heap_t **root, int value)
{

	heap_t *scooter = *root;
	heap_t *nodex = NULL;
	heap_t *newNode = NULL;

	if (scooter == NULL)
	{
		*root = malloc(sizeof(heap_t));
		(*root)->n = value;
		return (*root);
	}
	nodex = test(scooter);
	newNode = malloc(sizeof(heap_t));
	newNode->n = value;
	
	if (nodex->left)
	{
		nodex->right = newNode;
		newNode->parent = nodex;
	}
	else
	{
		nodex->left = newNode;
		newNode->parent = nodex;
	}
	return(newNode);
}
