#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the
 * left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 *
 * Return: a pointer to the created node, or NULL on failure or if parent
 *  
 * 
 *        is NULL
 */


binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;
	binary_tree_t *old_left_node;

	if (parent == NULL)
		return (NULL);

	old_left_node = parent->left;

	new_n = binary_tree_node(parent, value);

	if (new_n == NULL)
		return (NULL);

	parent->left = new_n;
	new_n->left = old_left_node;

	if (old_left_node != NULL)
		old_left_node->parent = new_n;

	return (new_n);
}

