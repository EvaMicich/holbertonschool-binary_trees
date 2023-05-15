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

/**
 * binary_tree_nodes - counts the nodes in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns number of leaves of tree, failure 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t c = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (binary_tree_is_leaf(tree) == 0)
	{
		c = c + 1;
	}
	c = c + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
	return (c);
}

