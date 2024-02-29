#include "binary_trees.h"

/**
 * avl_insert - inserts a new node into an avl tree
 * @tree: the tree to insert in
 * @value: the value to insert
 * Return: the node that was inserted
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;
	if (tree == NULL)
		return (NULL);

	node = binary_tree_node(NULL, value);

	if (node == NULL)
		return (NULL);

	if (*tree == NULL)
		*tree = node;
	else
		avl_insert_node(*tree, node, *tree);



	return (node);
}

avl_t *avl_insert_node(avl_t *tree, avl_t *node, avl_t *parent)
{
	if (tree == NULL)
	{
		node->parent = parent;
		return (node);
	}

	if (node->n < (tree)->n)
		(tree)->left = avl_insert_node((tree)->left, node, tree);
	else if (node->n > (tree)->n)
		(tree)->right = avl_insert_node((tree)->right, node, tree);
	else
		return (tree);
	//??
	int balance = binary_tree_balance((tree));
	if (balance > 1 && node->n < (tree)->left->n)
		return (binary_tree_rotate_right((tree)));

	if (balance < -1 && node->n > (tree)->right->n)
		return (binary_tree_rotate_left((tree)));

	if (balance > 1 && node->n > (tree)->left->n) {
		(tree)->left = binary_tree_rotate_left((tree)->left);
		return (binary_tree_rotate_right((tree)));
	}

	if (balance < -1 && node->n < (tree)->right->n) {
		(tree)->right = binary_tree_rotate_right((tree)->right);
		return (binary_tree_rotate_left((tree)));
	}

	return (tree);

}
