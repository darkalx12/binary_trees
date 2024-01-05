#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *twirl, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	twirl = tree->left;
	temp = twirl->right;
	twirl->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = twirl;
	twirl->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = twirl;
		else
			temp->right = twirl;
	}

	return (twirl);
}
