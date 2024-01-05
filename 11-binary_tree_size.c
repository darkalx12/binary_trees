#include "binary_trees.h"

/**
 * binary_tree_size - Measures the len of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the len of.
 *
 * Return: The len of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t len = 0;

	if (tree)
	{
		len += 1;
		len += binary_tree_size(tree->left);
		len += binary_tree_size(tree->right);
	}
	return (len);
}
