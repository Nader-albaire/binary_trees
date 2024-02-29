#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree node
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	new_n = malloc(sizeof(binary_tree_t));

	if (new_n == NULL)
		return (NULL);

	new_n->parent = parent;
	new_n->left = NULL;
	new_n->right = NULL;
	new_n->n = value;
	
	return (new_n);
}

