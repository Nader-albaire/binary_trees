#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */


int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t value = 1;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)

	{
		value = binary_tree_is_full(tree->left);

		if (value == 0)
			return (0);

		value = binary_tree_is_full(tree->right);

		if (value == 0)

			return (0);
	}
	
	else
		return (0);

	return (1);
}

