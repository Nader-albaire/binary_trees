#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node as the
 *  right-child of another node
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 *
 * Return: a pointer to the created node, or NULL on failure or if parent
 *         is NULL
 */


binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;
	binary_tree_t *old_right_node;

	if (parent == NULL)
		return (NULL);

	old_right_node = parent->right;

	new_n = binary_tree_node(parent, value);

	if (new_n == NULL)
		return (NULL);

	parent->right = new_n;
	new_n->right = old_right_node;

	if (old_right_node != NULL)
		old_right_node->parent = new_n;

	return (new_n);
}

