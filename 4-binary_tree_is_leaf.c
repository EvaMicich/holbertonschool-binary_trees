#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check is the node is a leaf
 * @node: the check
 *
 * Return: 1 for leaf, 0 for not a leaf
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}

	return (0);
}
