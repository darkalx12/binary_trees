#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the latest node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the latest node.
 *
 * Description: If parent already has a right-child, the latest node
 *              takes its place and the old right-child is set as
 *              the right-child of the latest node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *latest;

	if (parent == NULL)
		return (NULL);

	latest = binary_tree_node(parent, value);
	if (latest == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		latest->right = parent->right;
		parent->right->parent = latest;
	}
	parent->right = latest;

	return (latest);
}
