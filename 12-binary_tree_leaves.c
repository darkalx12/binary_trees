#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaf in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaf of.
 *
 * Return: The number of leaf in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (tree)
	{
		leaf += (!tree->left && !tree->right) ? 1 : 0;
		leaf += binary_tree_leaves(tree->left);
		leaf += binary_tree_leaves(tree->right);
	}
	return (leaf);
}
