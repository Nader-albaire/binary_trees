#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree.
 * @tree: is a pointer to the root node of the tree to measure the height
 *
 * Return: a binary tree height, If tree is NULL, your function must return 0
 */


size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left = (1 + binary_tree_height(tree->left));

	if (tree->right != NULL)
		right = (1 + binary_tree_height(tree->right));

	if (left > right)
		return (left);

	return (right);
}

