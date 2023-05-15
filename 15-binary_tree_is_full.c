#include "binary_trees.h"

/**
 * is_only_child - check if the node only has one child
 * @node: the node that need to be checked
 *
 * Return: 1 for the node only has one child , 0 for
 * the node has two children or has no child
 */

int is_only_child(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->left == NULL && node->right != NULL)
	{
		return (1);
	}
	else if (node->left != NULL && node->right == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * recursion_full - count if there is any node with only one child
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 for full tree, failure 0
 */
int recursion_full(const binary_tree_t *tree)
{
	size_t count = 0;
	size_t left_count = 0;
	size_t right_count = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (is_only_child(tree) == 1)
	{
		return (1);
	}

	left_count = recursion_full(tree->left);
	right_count = recursion_full(tree->right);
	count = left_count + right_count;

	return (count);
}

/**
 * binary_tree_is_full - check if binary tree is full or not
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 for full tree, failure 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int count = 0;

	if (tree == NULL)
	{
		return (0);
	}

	count = recursion_full(tree);

	if (count > 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
