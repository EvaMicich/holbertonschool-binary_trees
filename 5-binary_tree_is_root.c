#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 * @node: node check
 *
 * Return: 1 for root, 0 for not a root
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->parent == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
