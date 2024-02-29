#include "binary_trees.h"

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = *tree;
	bst_t *new_node;

	if (node == NULL)
	{
		new_node = (bst_t *) binary_tree_node(node, value);
		*tree = new_node;
		return (new_node);
	}

	if (value > node->n)
	{
		if (node->right == NULL)
		{
			new_node = (bst_t *) binary_tree_node(node, value);
			node->right = new_node;
			return (new_node);
		}
		return (bst_insert(&(node->right), value));
	}
	else if (value < node->n)
	{
		if (node->left == NULL)
		{
			new_node = binary_tree_node(node, value);
			node->left = new_node;
			return (new_node);
		}
		return (bst_insert(&(node->left), value));
	}
	return (NULL);
}
