#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs a right-rotation on
 *                           a binary tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	temp = tree->left->right;
	new_root = tree->left;

	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	tree->left = temp;

	if (temp != NULL)
		temp->parent = tree;

	return (new_root);
}
