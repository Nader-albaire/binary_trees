#include "binary_trees.h"


/**
 * binary_tree_node_h - a function that creates a binary tree node
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */


heap_t *binary_tree_node_h(heap_t *parent, int value)
{
	heap_t *new_node;

	new_node = malloc(sizeof(heap_t));

	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	return (new_node);
}



/**
 * swap_nodes - a function that swaps two nodes
 * @node1: is a pointer to the first node
 * @node2: is a pointer to the second node
 *
 * Return: Nothing
 */



void swap_nodes(heap_t **node1, heap_t **node2)
{
	int temp = (*node1)->n;
	(*node1)->n = (*node2)->n;
	(*node2)->n = temp;
}




/**
 * binary_tree_size - a function that measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 *
 * Return: a binary tree size, If tree is NULL, your function must return 0
 */


size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		size += binary_tree_size(tree->left);

	if (tree->right != NULL)
		size += binary_tree_size(tree->right);

	return (size);
}


/**
 * heap_insert - a function that inserts a value in Max Binary Heap
 * @root: is a double pointer to the root node of the Heap to insert the value
 * @value: is the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *array[1024];
	heap_t *node;
	int size;
	int i = 0;
	int j;

	if (root == NULL || *root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	size = binary_tree_size(*root);
	node = *root;

	array[i] = node;
	while (i < size && node != NULL)
	{
		if (array[i]->left != NULL && 2 * i + 1 < size)
			array[2 * i + 1] = array[i]->left;
		if (array[i]->right != NULL && 2 * i + 2 < size)
			array[2 * i + 2] = array[i]->right;
		i++;
	}
	array[i] = binary_tree_node_h(array[(size - 1) / 2], value);
	if (i % 2 == 1)
		array[(i - 1) / 2]->left = array[i];
	else
		array[(i - 1) / 2]->right = array[i];

	i = size;
	j = (size - 1) / 2;

	while (i >= 0 && j >= 0 && array[i]->n > array[j]->n)
	{
		swap_nodes(&(array[i]), &(array[j]));
		i = j;
		j = (i - 1) / 2;
	}
	return (array[i]);
}
