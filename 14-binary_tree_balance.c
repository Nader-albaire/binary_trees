#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance factor of
 *                       a binary tree
 * @tree: is a pointer to the root node of the tree to measure balance factor
 *
 * Return: a binary tree balance factor, If tree is NULL,
 *         your function must return 0
 */


int binary_tree_balance(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height_adjusted(tree->right);
	right = binary_tree_height_adjusted(tree->left);

	return (right - left);
}

/**
 * binary_tree_height_adjusted - a function that measures
 * the height of a binary tree + 1
 * @tree: is a pointer to the root node of the tree to measure the height.
 *
 * Return: a binary tree height, If tree is NULL, 
 * your function must return 0
 * 
 */
size_t binary_tree_height_adjusted(const binary_tree_t *tree)
{
	size_t left = 1;
	size_t right = 1;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left = (1 + binary_tree_height_adjusted(tree->left));

	if (tree->right != NULL)
		right = (1 + binary_tree_height_adjusted(tree->right));

	if (left > right)
	
		return (left);

	return (right);

}

