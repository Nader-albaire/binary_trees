#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 * @tree: is a pointer to the root node of the tree to count number of leaves
 *
 * Return: a binary tree leaves, If tree is NULL, 
 * 
 * your function must return 0
 */


size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		size += binary_tree_leaves(tree->left);

	if (tree->right != NULL)
		size += binary_tree_leaves(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (size);
}

