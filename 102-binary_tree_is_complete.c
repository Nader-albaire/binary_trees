#include "binary_trees.h"

/**
 * enqueue - a function that enqueue a new element
 * @my_queue: is a pointer to the queue
 * @node: the new node
 *
 * Return: Nothing
 */

void enqueue(queue *my_queue, const binary_tree_t *node)
{
	binary_tree_t *new_node;

	if (node == NULL)
		return;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return;

	new_node->parent = NULL;
	new_node->left = node->left;
	new_node->right = node->right;
	new_node->n = node->n;

	if (my_queue->front == NULL && my_queue->rear == NULL)
		my_queue->front = my_queue->rear = new_node;

	else
	{
		my_queue->rear->parent = new_node;
		my_queue->rear = new_node;
	}
}



/**
 * dequeue - a function that dequeue the front element
 * @my_queue: is a pointer to the queue
 *
 * Return: removed element
 */

binary_tree_t *dequeue(queue *my_queue)
{
	binary_tree_t *old;

	if (my_queue->front == NULL && my_queue->rear == NULL)
		return (NULL);

	old = my_queue->front;

	if (my_queue->front == my_queue->rear)
		my_queue->front = my_queue->rear = NULL;

	else
		my_queue->front = my_queue->front->parent;

	return (old);
}



/**
 * binary_tree_is_complete - a function that checks if binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue *new_queue;
	binary_tree_t *root;
	int flag = 0;

	if (tree == NULL)
		return (0);
	new_queue = malloc(sizeof(queue));
	if (new_queue == NULL)
		return (0);
	new_queue->front = NULL;
	new_queue->rear = NULL;
	root = (binary_tree_t *) tree;
	enqueue(new_queue, tree);
	while (root != NULL)
	{
		if ((flag >= 1 && root->left != NULL) ||
			(root->left == NULL && root->right != NULL))
		{
			while (root != new_queue->rear)
			{
				new_queue->front = root->parent;
				free(root);
				root = new_queue->front;
			}
			free(root);
			free(new_queue);
			return (0);
		}

		if (root->left != NULL && root->right == NULL)
			flag++;

		enqueue(new_queue, root->left);
		enqueue(new_queue, root->right);
		root = dequeue(new_queue);
		free(root);
		root = new_queue->front;
	}
	free(new_queue);
	return (1);
}

