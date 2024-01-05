#include "binary_trees.h"

/**
 * create_node - Creates a new level_queue_time node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
level_queue_time *create_node(binary_tree_t *node)
{
	level_queue_time *new;

	new = malloc(sizeof(level_queue_time));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * set_queue - Frees a level_queue_time queue.
 * @head: A pointer to the head of the queue.
 */
void set_queue(level_queue_time *head)
{
	level_queue_time *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * print_push - Runs a function on a given binary tree node and
 *             pushes its children into a level_queue_time queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void print_push(binary_tree_t *node, level_queue_time *head,
		level_queue_time **tail, void (*func)(int))
{
	level_queue_time *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			set_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			set_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * dad - Pops the head of a level_queue_time queue.
 * @head: A double pointer to the head of the queue.
 */
void dad(level_queue_time **head)
{
	level_queue_time *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	level_queue_time *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		print_push(head->node, head, &tail, func);
		dad(&head);
	}
}
