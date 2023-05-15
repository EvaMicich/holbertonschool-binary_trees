#include "binary_trees.h"

/**
 * binary_tree_size - finds size of binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns size of tree, failure 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;
	size_t left_count = 0;
	size_t right_count = 0;

	if (tree == NULL)
	{
		return (0);
	}
	left_count = binary_tree_size(tree->left);
	right_count = binary_tree_size(tree->right);
	count = left_count + right_count + 1;
	return (count);
}

