#include "binary_trees.h"

/**
 * binary_tree_nodes - a function that counts the nodes with at least
 *                     1 child in a binary tree
 * @tree: is a pointer to the root node of the tree to count number of nodes
 *
 * Return: a binary tree nodes, If tree is NULL, your function must return 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t size = 0;

    if (tree == NULL)
        return (0);

    if (tree->left != NULL || tree->right != NULL)
        size++;

    size += binary_tree_nodes(tree->left);
    size += binary_tree_nodes(tree->right);

    return (size);
}

