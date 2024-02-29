#include "binary_trees.h"


/**
 * search_node - a function that searches for a specific node
 * @root: is a pointer to the root node
 * @to_search: is a pointer to the node to search
 *
 * Return: 1 for success, 0 for fail
 */

int search_node(const binary_tree_t *root, const binary_tree_t *to_search)
{
	if (root == NULL)
		return (0);

	if (root == to_search)
		return (1);

	if (search_node(root->left, to_search) == 1)
		return (1);

	if (search_node(root->right, to_search) == 1)
		return (1);

	return (0);
}




/**
 * binary_trees_ancestor - a function that finds the lowest
 *                         common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 *
 * Return: a pointer to the uncle node
 */


binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	binary_tree_t *ancestor = (binary_tree_t *)first;
	int found = 0;

	while (ancestor != NULL)
	{
		found = search_node(ancestor, second);

		if (found == 1)
			break;

		ancestor = ancestor->parent;
	}

	return (ancestor);
}
