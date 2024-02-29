#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that performs a left-rotation on
 *                           a binary tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	temp = tree->right->left;
	new_root = tree->right;

	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	tree->right = temp;

	if (temp != NULL)
		temp->parent = tree;

	return (new_root);
}
