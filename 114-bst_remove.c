#include "binary_trees.h"


/**
 * smallest_right - a function that gets the smallest right value
 * @tree: is a pointer to the root node of the BST to search
 *
 * Return: a pointer to the node containing that value
 */

bst_t *smallest_right(const bst_t *tree)
{
	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return ((bst_t *) tree);

	return (smallest_right(tree->left));
}


/**
 * bst_search - a function that searches for a value in a Binary Search Tree
 * @tree: is a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 *
 * Return: a pointer to the node containing a value equals to value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value > tree->n)
		return (bst_search(tree->right, value));

	if (value < tree->n)
		return (bst_search(tree->left, value));

	return ((bst_t *) tree);
}



/**
 * remove_node_with_zero_one_child - a function that removes
 *                                   a node from a Binary Search Tree
 * @node: node to remove
 * @child: node to remove's child
 * @parent: node to remove's parent
 *
 * Return: Nothing
 */


void remove_node_with_zero_one_child(bst_t *node, bst_t *child, bst_t *parent)
{
	if (parent != NULL)
	{
		if (parent->left == node)
			parent->left = child;
		else if (parent->right == node)
			parent->right = child;
	}
	if (child != NULL)
		child->parent = parent;
	free(node);
}



/**
 * bst_remove - a function that removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree where you will remove node
 * @value: is the value to remove in the tree
 *
 * Return: a pointer to the node containing a value equals to value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *parent;
	bst_t *to_remove;
	bst_t *smallest;

	if (root == NULL)
		return (NULL);

	to_remove = bst_search(root, value);

	if (to_remove == NULL)
		return (NULL);


	parent = to_remove->parent;

	if (to_remove->left == NULL && to_remove->right == NULL)
		remove_node_with_zero_one_child(to_remove, NULL, parent);

	else if (to_remove->left == NULL && to_remove->right != NULL)
		remove_node_with_zero_one_child(to_remove, to_remove->right, parent);

	else if (to_remove->left != NULL && to_remove->right == NULL)
		remove_node_with_zero_one_child(to_remove, to_remove->left, parent);

	else if (to_remove->left != NULL && to_remove->right != NULL)
	{
		smallest = smallest_right(to_remove->right);
		to_remove->n = smallest->n;
		if (smallest->parent->left == smallest)
			smallest->parent->left = NULL;
		else
			smallest->parent->right = NULL;
		free(smallest);
	}

	return (root);
}
