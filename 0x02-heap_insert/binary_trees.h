#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;
typedef struct binary_tree_s heap_t;

struct queue_s
{
	heap_t *array[2065];
	int front;
	int reer;
	int flag;
} queue_s;

struct queue_s queue;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
void enqueue(heap_t *node);
void dequeue(void);
heap_t *testx(heap_t **root);
void heap_parent_vs_child(heap_t **son, heap_t **father);
void swapNode(heap_t **mynode);
#endif /* _BINARY_TREES_H_ */

