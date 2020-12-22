#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

heap_t *test(heap_t *node) {

	heap_t *stack[2024];
	heap_t *tempNode = NULL;
	int i = 0;

	stack[i] = node;
	printf("okkkk");
	while(1) {
		tempNode = stack[i];
		if(tempNode->left == NULL || tempNode->right ==NULL)
		{
			printf("%d", tempNode->n);
			printf("success");
			break;
		}
		i++;
		stack[i] = tempNode->left;
		i++;
		stack[i] = tempNode->right;
		}
		return (tempNode);
}
