#include "binary_trees.h"


/**
 * binary_tree_sibling - a function that finds the sibling of a node
 * 
 * @node: is a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node
 */


binary_tree_t *binary_tree_sibling(binary_tree_t *node)

{
	binary_tree_t *sibling;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->right)
		sibling = node->parent->left;
	else
		sibling = node->parent->right;

	return (sibling);
}

