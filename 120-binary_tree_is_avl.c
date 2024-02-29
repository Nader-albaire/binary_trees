#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a tree is a valid avl tree
 * @tree: the tree to check
 * Return: 1 if valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isBalancedAvl(tree));
}

/**
 * isBalancedAvl - checks if a tree is a valid avl tree
 * @tree: the tree to check
 * Return: 1 if valid AVL tree, 0 otherwise
 */
int isBalancedAvl(const binary_tree_t *tree)
{
	int leftHeight = 0;
	int rightHeight = 0;
	int difference;
	int isBalanced;
	int isBalancedRight = 1;
	int isBalancedLeft = 1;
	int finalBalance;

	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->n < tree->left->n)
		return (0);
	if (tree->right != NULL && tree->n > tree->right->n)
		return (0);

	if (tree->left != NULL)
	{
		leftHeight = (int)binary_tree_height_adjusted(tree->left);
		if (!binary_tree_preorder_check_left(tree->left, tree->n))
			return (0);
	}
	if (tree->right != NULL)
	{
		rightHeight = (int)binary_tree_height_adjusted(tree->right);
		if (!binary_tree_preorder_check_right(tree->right, tree->n))
			return (0);
	}

	difference = leftHeight - rightHeight;
	isBalanced = !(difference >= 2 || difference <= -2);
	if (tree->left != NULL)
		isBalancedLeft = isBalancedAvl(tree->left);
	if (tree->right != NULL)
		isBalancedRight = isBalancedAvl(tree->right);
	finalBalance = isBalanced && isBalancedRight && isBalancedLeft;
	return (finalBalance);
}

/**
 * binary_tree_preorder_check_left - a function
 * that goes through a binary tree using
 *                        pre-order traversal
 *                        checking if any value is bigger than the value given.
 * @tree: is a pointer to the root node of the tree to traverse
 * @value: the value to check
 *
 * Return: Nothing
 */
int binary_tree_preorder_check_left(const binary_tree_t *tree, int value)
{
	int rightCheck;
	int leftCheck;
	

	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > value)
		return (0);
	if (tree->right != NULL && tree->right->n > value)
		return (0);
	leftCheck = binary_tree_preorder_check_left(tree->left, value);
	rightCheck = binary_tree_preorder_check_left(tree->right, value);
	return (leftCheck && rightCheck);
}

/**
 * binary_tree_preorder_check_right - a function that goes through
 * a binary tree using
 * pre-order traversal
 * checking if any value is smaller than the value given
 * @tree: is a pointer to the root node of the tree to traverse
 * @value: the value to check
 *
 * Return: Nothing
 */
int binary_tree_preorder_check_right(const binary_tree_t *tree, int value)
{
	int leftCheck;
	int rightCheck;

	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n < value)
		return (0);
	if (tree->right != NULL && tree->right->n < value)
		return (0);
	leftCheck = binary_tree_preorder_check_right(tree->left, value);
	rightCheck = binary_tree_preorder_check_right(tree->right, value);
	return (leftCheck && rightCheck);
}

/**
 * binary_tree_height_adjusted - a function that measures
 * the height of a binary tree + 1
 * @tree: is a pointer to the root node of the tree to measure the height.
 *
 * Return: a binary tree height, If tree is NULL, your function must return 0
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

