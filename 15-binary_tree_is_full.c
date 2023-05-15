#include "binary_trees.h"

/**
 * is_only_child - check is the node is a leaf
 * @node: the check
 *
 * Return: 1 for leaf, 0 for not a leaf
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
 * binary_tree_is_full - check if binary tree is full or not
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 for full tree, failure 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
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
	left_count = binary_tree_is_full(tree->left);
	right_count = binary_tree_is_full(tree->right);

	count = left_count + right_count;
	printf("count is %zu\n", count);
	if (count > 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
