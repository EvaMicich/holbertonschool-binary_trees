#include "binary_trees.h"


/**
 * recursion_height - finds height + 1
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns height of tree + 1, failure 0
 */

size_t recursion_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = recursion_height(tree->left);
	right_height = recursion_height(tree->right);

	if (left_height > right_height)
	{
		left_height = left_height + 1;
		return (left_height);
	}
	else
	{
		right_height = right_height + 1;
		return (right_height);
	}
}

/**
 * binary_tree_height - finds height of binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns height of tree, failure 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	height = recursion_height(tree) - 1;
	return (height);
}
