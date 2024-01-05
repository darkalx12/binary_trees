#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @result: The result to put in the new node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_d *binary_tree_node(binary_tree_d *parent, int result)
{
	binary_tree_d *new;

	new = malloc(sizeof(binary_tree_d));
	if (new == NULL)
		return (NULL);

	new->n = result;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
