#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the resent node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the resent node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *resent;

	resent = malloc(sizeof(binary_tree_t));
	if (resent == NULL)
		return (NULL);

	resent->n = value;
	resent->parent = parent;
	resent->left = NULL;
	resent->right = NULL;

	return (resent);
}
