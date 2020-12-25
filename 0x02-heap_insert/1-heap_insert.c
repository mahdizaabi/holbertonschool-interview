#include "binary_trees.h"
/**
 *swap- sawping the value of 2 nodes
 *@n1: node 1
 *@n2: node2
 * 
 *Return: void
 */

void swap(heap_t* n1, heap_t* n2)
{
	int tmp = n2->n;

		n2->n = n1->n;
		n1->n = tmp;
		n1 = n2;
}

/**
 *binary_tree_depth- measures the depth of a node in a binary tree
 *@tree:a pointer to the node to measure the depth
 *
 *Return: the depth of node or 0 id tree NULL
 */
size_t binary_tree_depth(heap_t *tree)
{
size_t d = 0;
	if (!tree || !tree->parent)
		return (d);

	d = binary_tree_depth(tree->parent) + 1;

return (d);
}

/**
 * insert_node - functin to insert a node in the right position
 * @node: pointer to node
 * @lvl: the insertion node level
 * @value: integer
 *
 * Return: a pointer to the node to insert
 */

heap_t *insert_node(heap_t *node, size_t lvl, int value)
{
	heap_t *n1, *n2;

	if (!node)
		return (NULL);

	if (binary_tree_depth(node) == lvl)
	{
		if (!node->left && !node->right)
		{
			return (node->left = binary_tree_node(node, value));
		}

		if (node->left && !node->right)
		{
			return (node->right = binary_tree_node(node, value));
		}

		return (NULL);

	}

	n1 = insert_node(node->left, lvl, value);

	if (!n1)
		n2 = insert_node(node->right, lvl, value);
	else
		return (n1);
	return (n2);
}

/**
 *binary_tree_height- measures the height of a binary tree
 *@tree: a pointer to the root node of the tree to measure the height.
 *Return: nbr of level
 */
size_t binary_tree_height(heap_t *tree)
{
size_t nr = 0, nf = 0;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);
	nf = binary_tree_height(tree->left) + 1;
	nr = binary_tree_height(tree->right) + 1;
	if (nf > nr)
		return (nf);
	else
		return (nr);
}

/**
 * heap_insert - a function to insert a value into a Max binary heap
 * @root: a double pointer to the heap root node
 * @value: value to be inserted
 *
 * Return: the pointer to the inserted new node, otherwise NULL
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	size_t lvl = 0, i;


	if (!root)
		return (NULL);

	if (!(*root))
	{
		new_node = binary_tree_node(*root, value);
		*root = new_node;
		return (new_node);
	}

	lvl = binary_tree_height(*root);

	for (i = 0; i <= lvl; i++)
	{
		new_node = insert_node(*root, i, value);
		if (new_node)
			break;
	}
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap(new_node, new_node->parent);
		new_node = new_node->parent;
	}

	return (new_node);
}
