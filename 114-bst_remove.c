#include "binary_trees.h"
/**
 * owner - get the next owner i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int owner(bst_t *node)
{
	int left_side = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left_side = owner(node->left_side);
		if (left_side == 0)
		{
			return (node->n);
		}
		return (left_side);
	}

}
/**
 * second_child - function that gets the next owner using the min
 * value in the right subtree, and then replace the node value for
 * this owner
 * @root: node tat has two children
 * Return: the value found
 */
int second_child(bst_t *root)
{
	int new_value = 0;

	new_value = owner(root->right);
	root->n = new_value;
	return (new_value);
}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	if (!root->left_side && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left_side = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left_side && root->right) || (!root->right && root->left_side))
	{
		if (!root->left_side)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left_side = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left_side;
			else
				root->parent->left_side = root->left_side;
			root->left_side->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (second_child(root));
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left_side, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
