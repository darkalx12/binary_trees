#include "binary_trees.h"

void push(binary_tree_t *node, level_queue_t *head,
		level_queue_t **tail);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new level_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
level_queue_t *create_node(binary_tree_t *node)
{
	level_queue_t *new;

	new = malloc(sizeof(level_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * set_queue - Frees a level_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void set_queue(level_queue_t *head)
{
	level_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes a node to the back of a level_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, level_queue_t *head,
		level_queue_t **tail)
{
	level_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		set_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * dad - Pops the head of a level_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void dad(level_queue_t **head)
{
	level_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	level_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				set_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				set_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		dad(&head);
	}
	return (1);
}
