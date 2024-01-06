#include "binary_trees.h"
#include "limits.h"

size_t dept(const binary_tree_t *tree);
int is_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * dept - Measures the dept of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the dept.
 *
 * Return: If tree is NULL, your function must return 0, else return dept.
 */
size_t dept(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t a = 0, r = 0;

		a = tree->left ? 1 + dept(tree->left) : 1;
		r = tree->right ? 1 + dept(tree->right) : 1;
		return ((a > r) ? a : r);
	}
	return (0);
}

/**
 * is_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t ldp, rdp, different;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		ldp = dept(tree->left);
		rdp = dept(tree->right);
		different = ldp > rdp ? ldp - rdp : rdp - ldp;
		if (different > 1)
			return (0);
		return (is_helper(tree->left, lo, tree->n - 1) &&
			is_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_helper(tree, INT_MIN, INT_MAX));
}
