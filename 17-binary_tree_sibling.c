#include "binary_trees.h"

/**
 * binary_tree_sibling - finds sibling in binary tree
 * @node: the node to find sibling for
 *
 * Return: address of sibling, NULL for failure
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->left == node)
	{
		if (node->parent->right == NULL)
		{
			return (NULL);
		}
		return (node->parent->right);
	}
	else if (node->parent->right == node)
	{
		if (node->parent->left == NULL)
		{
			return (NULL);
		}
		return (node->parent->left);
	}
	return (NULL);
}
