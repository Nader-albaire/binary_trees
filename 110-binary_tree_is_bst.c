#include "binary_trees.h"

/**
 * check_bigger - checking right part of the root
 * @tree: is a pointer to the root node of the tree to check
 * @node_to_check: new upcoming node to check
 *
 * Return: 0 if not valid, 1 if valid
 */


int check_bigger(const binary_tree_t *tree, const binary_tree_t *node_to_check)
{
	if (node_to_check == NULL)
		return (1);

	if (node_to_check->n > tree->n)
		return (check_bigger(tree, node_to_check->left) &&
				check_bigger(tree, node_to_check->right));
	else
		return (0);
}

/**
 * check_lower - checking left part of the root
 * @tree: is a pointer to the root node of the tree to check
 * @node_to_check: new upcoming node to check
 *
 * Return: 0 if not valid, 1 if valid
 */

int check_lower(const binary_tree_t *tree, const binary_tree_t *node_to_check)
{
	if (node_to_check == NULL)
		return (1);

	if (node_to_check->n < tree->n)
		return (check_lower(tree, node_to_check->left) &&
				check_lower(tree, node_to_check->right));
	else
		return (0);
}


/**
 * binary_tree_is_bst - a function that checks if a binary tree is
 *                      a valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: must return 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		binary_tree_is_bst(tree->left);
	if (tree->right != NULL)
		binary_tree_is_bst(tree->right);

	return (check_bigger(tree, tree->right) && check_lower(tree, tree->left));

}
